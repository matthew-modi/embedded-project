module camera_interface (
    input logic clk,
    input logic reset,
    input logic [7:0] d,
    input logic href,
    input logic vsync,
    input logic hsync,
    output logic [7:0] q
);
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            q <= 8'b0;
        end else if (href) begin
            q <= d;
        end
    end
endmodule