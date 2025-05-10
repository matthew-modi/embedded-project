#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#define TP_PER_LINE 784
#define TOTAL_LINES 525
#define HSYNC_PULSE_TP 96
#define BACK_PORCH_TP 48
#define VISIBLE_PIXELS 640
#define VSYNC_START_LINE 10
#define VSYNC_END_LINE 12
#define VISIBLE_LINE_START 45
#define VISIBLE_LINE_END 524

int main() {
    Verilated::traceEverOn(true);
    Vtop* dut = new Vtop;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("dump.vcd");

    dut->reset = 0;
    dut->clk = 0;
    dut->d = 0;
    dut->href = 0;
    dut->vsync = 1;
    dut->hsync = 1;

    int cycle = 0;

    for (int line = 0; line < TOTAL_LINES; ++line) {
        int pixel = 0;
        bool first_byte = true;

        for (int tp = 0; tp < TP_PER_LINE; ++tp) {
            for (int sub = 0; sub < 2; ++sub) { // 2 cycles per tP (tPCLK)
                int current_cycle = cycle++;

                // VSYNC logic
                dut->vsync = (line >= VSYNC_START_LINE && line < VSYNC_END_LINE) ? 0 : 1;

                // HSYNC logic
                dut->hsync = (tp < HSYNC_PULSE_TP) ? 0 : 1;

                // HREF logic
                bool href_active = (line >= VISIBLE_LINE_START && line <= VISIBLE_LINE_END && tp >= (HSYNC_PULSE_TP + BACK_PORCH_TP) && tp < (HSYNC_PULSE_TP + BACK_PORCH_TP + VISIBLE_PIXELS));
                dut->href = href_active ? 1 : 0;

                // Rising edge
                dut->clk = 1;
                dut->eval();
                tfp->dump(current_cycle * 2);

                // Falling edge (pixel update on second cycle of tP)
                dut->clk = 0;
                if (href_active && sub == 1) {
                    if (first_byte) {
                        dut->d = (pixel & 0x1F) << 2; // R[4:0] in D[6:2], G[4:3] = 0
                    } else {
                        dut->d = ((pixel & 0x7) << 5) | (pixel & 0x1F); // G[2:0] in D[7:5], B[4:0] in D[4:0]
                        pixel++;
                    }
                    first_byte = !first_byte;
                } else {
                    dut->d = 0;
                    first_byte = true;
                }
                dut->eval();
                tfp->dump(current_cycle * 2 + 1);
            }
        }
    }

    tfp->close();
    delete dut;
    return 0;
}
