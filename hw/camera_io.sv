module camera_io (
  input logic       clk,         // 25 MHz PLL
  input  logic        reset,       // active‐high synchronous reset

  output logic        cam_xclk,       // 25 MHz pixel clock to camera
  input  logic        cam_pclk,        // 25 MHz pixel clock from camera
  input  logic        cam_href,    // row‐valid from camera
  input  logic        cam_vsync,   // frame‐valid from camera
  input  logic [7:0]  cam_data,    // one byte of RGB565 per cycle
  input logic         switch_shutter,

  output logic       fpga_pclk,
  output logic       fpga_href,    // row‐valid to FPGA
  output logic       fpga_vsync,   // frame‐valid to FPGA
  output logic [7:0] fpga_data,    // one byte of RGB565 to FPGA
  output logic       fpga_shutter
    );
    assign cam_xclk = clk;
    assign fpga_pclk = cam_pclk;
endmodule