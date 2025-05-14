// vga_interface.sv
// Simplified OV7670→VGA using HREF/VSYNC directly as HS/VSYNC.
// Assumes pclk = 25 MHz pixel clock.

module vga_interface (
  input logic       clk,         // 25 MHz PLL
  input  logic        reset,       // active‐high synchronous reset

  output logic        cam_xclk,       // 25 MHz pixel clock to camera
  input  logic        cam_pclk,        // 25 MHz pixel clock from camera
  input  logic        cam_href,    // row‐valid from camera
  input  logic        cam_vsync,   // frame‐valid from camera
  input  logic [7:0]  cam_data,    // one byte of RGB565 per cycle

  output logic        VGA_CLK,     
  output logic        VGA_HS,      // driven by cam_href
  output logic        VGA_VS,      // driven by cam_vsync
  output logic        VGA_BLANK_n, // active when cam_href
  output logic        VGA_SYNC_n,  // unused
  output logic [7:0]  VGA_R, VGA_G, VGA_B
);
  assign xclk = clk;  // use same clock for camera

  // Assemble 16‐bit RGB565 over two bytes
  logic        byte_flag;
  logic [15:0] pix16;

  always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
      byte_flag <= 1'b0;
      pix16     <= 16'd0;
    end else if (cam_href) begin
      if (!byte_flag)
        pix16[15:8] <= cam_data;  // first half‐pixel
      else
        pix16[7:0]  <= cam_data;  // second half‐pixel
      byte_flag <= ~byte_flag;
    end else begin
      byte_flag <= 1'b0;          // resync at each row end
    end
  end

  // Zero‐pad LSBs for 5-6-5 → 8-bit per channel
  assign VGA_R = { pix16[15:11], 3'b000 };
  assign VGA_G = { pix16[10:5],  2'b00  };
  assign VGA_B = { pix16[4:0],   3'b000 };

  // Drive VGA signals directly from camera strobes
  assign VGA_CLK     = clk;
  assign VGA_HS      = cam_href;    // use HREF instead of standard hsync
  assign VGA_VS      = cam_vsync;   // use VSYNC directly
  assign VGA_BLANK_n = cam_href;    // blank when not in a valid row
  assign VGA_SYNC_n  = 1'b1;        // not used on this board

endmodule
