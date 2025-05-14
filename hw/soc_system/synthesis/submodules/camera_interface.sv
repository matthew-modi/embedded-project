module camera_interface (
	//mock input 
	input reset,

	//camera inputs
	input logic href,
	input logic vsync,
	input logic pclk,
	input logic [7:0] d,

	//other inputs 
	input logic shutter_raw, //assume shutter is active low

	//outputs 
	output logic fifo_enable,
	output logic [31:0] wide_bit_out
	);

	typedef enum logic [1:0] {
	    RESET,
	    SHUTTER,
	    WRITE,
	    BLOCK
	} state_t;

	state_t state;

	logic [10:0] col_count;
	logic [8:0] row_count;
	logic [2:0] clk_count;
	logic [7:0] q;

	logic shutter;
	logic write_enable;
	logic prev_vsync;
	logic curr_vsync; 
	logic write_trigger;
	logic rst;

	assign curr_vsync = vsync;

	assign write_enable = (href && (row_count == 239)) ? 1 : 0;

	assign write_trigger = write_enable;

	always_ff @(posedge pclk) begin

		if (reset) begin
			state      <= RESET;
			col_count  <= 0;
			row_count  <= 0;
			prev_vsync <= 0;
			rst <= 1;
		end else begin
			if ((shutter) && ((row_count < 1) || (row_count > 240)))
				state <= RESET; 
			else case (state)
				RESET : begin
					if (vsync) begin
						col_count <= 11'b0;
						row_count <= 9'b0;
						state <= SHUTTER;
						rst <= 1;
					end
				end
				SHUTTER : begin
					rst <= 0;
					if ((col_count == 11'd0) && (href))
						row_count <= row_count + 1;
					if ((col_count < 11'd1279) && (href))
						col_count <= col_count + 1;
					if ((col_count == 11'd1279) && (href)) begin
						col_count <= 0;
					end
					if ((write_trigger) && (href))
						state <= WRITE;
				end
				WRITE : begin
					if ((col_count < 11'd1279) && (href))
						col_count <= col_count + 1;
					if ((col_count == 11'd1279) && (href)) begin
						col_count <= 0;
						row_count <= row_count + 1;
					end
					if ((row_count==240) && (href))
						state <= BLOCK;
				end
				BLOCK : begin
					prev_vsync <= curr_vsync; 
				end
				default: state <= BLOCK;
			endcase
		end	
	end

	always_ff @(posedge pclk) begin
		if ((write_enable) && (clk_count == 3'd3) && (row_count == 239)) begin
			clk_count <= 3'd0;
		end else if ((clk_count < 3'd4) && (write_enable)) begin 
			clk_count <= clk_count + 1;	
		end
	end

	always_ff @(negedge pclk) begin

		if ((write_enable) && (clk_count == 3'd0)) begin
			wide_bit_out[15:8] <= q[7:0];
			fifo_enable <= 0;
		end 
		else if ((write_enable) && (clk_count == 3'd1)) begin
			wide_bit_out[7:0] <= q[7:0];
			fifo_enable <= 0;
		end 
		else if ((write_enable) && (clk_count == 3'd2)) begin
			wide_bit_out[31:24] <= q[7:0];
			fifo_enable <= 0;
		end 
		else if ((write_enable) && (clk_count == 3'd3)) begin
			wide_bit_out[23:16] <= q[7:0];
			fifo_enable <= 1;
		end 
	end

	flipflip uut0 (.clk(pclk), .rst(rst), .en(href), .d(d[0]), .q(q[0]));
	flipflip uut1 (.clk(pclk), .rst(rst), .en(href), .d(d[1]), .q(q[1]));
	flipflip uut2 (.clk(pclk), .rst(rst), .en(href), .d(d[2]), .q(q[2]));
	flipflip uut3 (.clk(pclk), .rst(rst), .en(href), .d(d[3]), .q(q[3]));
	flipflip uut4 (.clk(pclk), .rst(rst), .en(href), .d(d[4]), .q(q[4]));
	flipflip uut5 (.clk(pclk), .rst(rst), .en(href), .d(d[5]), .q(q[5]));
	flipflip uut6 (.clk(pclk), .rst(rst), .en(href), .d(d[6]), .q(q[6]));
	flipflip uut7 (.clk(pclk), .rst(rst), .en(href), .d(d[7]), .q(q[7]));

	debounce_better_version uut8(.pb_1(shutter_raw), .clk(pclk), .pb_out(shutter));


endmodule


