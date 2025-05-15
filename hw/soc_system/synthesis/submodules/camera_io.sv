module camera_io (
  input logic       clk,         // 25 MHz PLL
  input  logic        reset,       // active‐high synchronous reset

  input  logic        cam_href,    // row‐valid from camera
  input  logic        cam_vsync,   // frame‐valid from camera
  input  logic [7:0]  cam_data,    // one byte of RGB565 per cycle
  input logic         switch_shutter,

  output logic       href,    // row‐valid to FPGA
  output logic       vsync,   // frame‐valid to FPGA
  output logic [7:0] d,    // one byte of RGB565 to FPGA
  output logic       shutter_raw
    );
    assign shutter_raw = switch_shutter;
    assign d = cam_data;
    assign href = cam_href;
    assign vsync = cam_vsync;
endmodule