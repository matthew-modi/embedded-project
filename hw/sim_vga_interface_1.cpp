#include "Vvga_interface.h"
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
    Vvga_interface* dut = new Vvga_interface;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("dump.vcd");

    dut->reset = 0;
    dut->pclk = 0;
    dut->cam_data = 0;
    dut->cam_href = 0;
    dut->cam_vsync = 1;

    int cycle = 0;

    for (int line = 0; line < TOTAL_LINES; ++line) {
        bool first_byte = true;

        for (int tp = 0; tp < TP_PER_LINE; ++tp) {
            for (int sub = 0; sub < 2; ++sub) { // 2 clocks per tP
                int current_cycle = cycle++;

                // VSYNC
                dut->cam_vsync = (line >= VSYNC_START_LINE && line < VSYNC_END_LINE) ? 0 : 1;

                // cam_href high for 640 tP (i.e. 1280 clocks)
                bool cam_href_active = (
                    line >= VISIBLE_LINE_START &&
                    line <= VISIBLE_LINE_END &&
                    tp >= (HSYNC_PULSE_TP + BACK_PORCH_TP) &&
                    tp < (HSYNC_PULSE_TP + BACK_PORCH_TP + VISIBLE_PIXELS)
                );
                dut->cam_href = cam_href_active ? 1 : 0;

                // Rising edge
                dut->pclk = 1;
                dut->eval();
                tfp->dump(current_cycle * 2);

                // Falling edge
                dut->pclk = 0;
                if (cam_href_active) {
                    dut->cam_data = first_byte ? 0xF8 : 0x00; // Solid red in RGB565
                    first_byte = !first_byte;
                } else {
                    dut->cam_data = 0;
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
