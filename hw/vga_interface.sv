// camera_to_vga.sv
// Streams OV7670 pixels straight to a VGA panel using a single 25 MHz clock.
// HREF gates valid data; we generate our own front/back porches and sync pulses.

module camera_to_vga (
  input  logic        clk25,        // 25 MHz XCLK → camera PCLK & VGA pixel clock
  input  logic        reset,        
  input  logic        href,         // camera row‐valid strobe
  input  logic        vsync_cam,    // camera frame strobe (unused for VGA sync)
  input  logic [7:0]  cam_data,     // one byte per cycle from camera

  output logic        VGA_HS,       
  output logic        VGA_VS,       
  output logic        VGA_BLANK_n,  
  output logic        VGA_SYNC_n,   
  output logic        VGA_CLK,      
  output logic [7:0]  VGA_R, VGA_G, VGA_B
);

  // VGA timing (640×480 @25 MHz)
  localparam H_ACTIVE   = 11'd640, H_FP = 11'd16, H_SYNC_P = 11'd96, H_BP = 11'd48;
  localparam V_ACTIVE   = 10'd480, V_FP = 10'd10, V_SYNC_P = 10'd2,  V_BP = 10'd33;
  localparam H_TOTAL = H_ACTIVE + H_FP + H_SYNC_P + H_BP;  // 800
  localparam V_TOTAL = V_ACTIVE + V_FP + V_SYNC_P + V_BP;  // 525

  logic [10:0] hcnt;
  logic [ 9:0] vcnt;
  logic [7:0]  pixel_reg;

  // 1) Counters & pixel latch (single domain)
  always_ff @(posedge clk25 or posedge reset) begin
    if (reset) begin
      hcnt      <= 0;
      vcnt      <= 0;
      pixel_reg <= 0;
    end else begin
      // horizontal line counter
      if (hcnt == H_TOTAL-1) hcnt <= 0;
      else                   hcnt <= hcnt + 1;
      // vertical frame counter
      if (hcnt == H_TOTAL-1) begin
        if (vcnt == V_TOTAL-1) vcnt <= 0;
        else                   vcnt <= vcnt + 1;
      end
      // latch camera byte when href indicates valid pixel
      if (href)
        pixel_reg <= cam_data;
    end
  end

  // 2) Sync and blank signals
  // HSYNC active low during sync pulse
  assign VGA_HS      = ~((hcnt >= H_ACTIVE+H_FP) &&
                         (hcnt <  H_ACTIVE+H_FP+H_SYNC_P));
  // VSYNC active low during sync pulse
  assign VGA_VS      = ~((vcnt >= V_ACTIVE+V_FP) &&
                         (vcnt <  V_ACTIVE+V_FP+V_SYNC_P));
  // blank_n is high only during visible region
  assign VGA_BLANK_n = (hcnt < H_ACTIVE) && (vcnt < V_ACTIVE);
  assign VGA_SYNC_n  = 1'b1;        // unused on most VGA monitors
  assign VGA_CLK     = clk25;       // drive the monitor’s pixel clock

  // 3) Color output (grayscale)
  always_comb begin
    if (VGA_BLANK_n)
      VGA_R = VGA_G = VGA_B = pixel_reg;
    else
      VGA_R = VGA_G = VGA_B = 8'h00;
  end

endmodule
