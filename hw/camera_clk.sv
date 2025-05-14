module camera_clk (
  input logic      clk,

  output logic        cam_xclk,
  input  logic        cam_pclk,

  output logic       fpga_pclk
    );
    assign cam_xclk = clk;
    assign fpga_pclk = cam_pclk;
endmodule
