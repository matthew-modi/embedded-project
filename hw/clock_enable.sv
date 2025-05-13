/*
// Slow clock enable for debouncing button 
module clock_enable(input Clk,output slow_clk_en);
    reg [26:0]counter=0;
    always @(posedge Clk_100M)
    begin
       counter <= (counter>=249999)?0:counter+1;
    end

    assign slow_clk_en = (counter == 249999)?1'b1:1'b0;
endmodule
*/

// Generates a 1-clock-cycle pulse every 10 clock cycles

module clock_enable (
    input  logic clk,
    output logic slow_clk_en
);
    reg [3:0] counter = 0; // 4-bit counter is enough for values 0–9

    always_ff @(posedge clk) begin
        if (counter == 9)
            counter <= 0;
        else
            counter <= counter + 1;
    end

    assign slow_clk_en = (counter == 9);

endmodule



