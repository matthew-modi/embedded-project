#include "Vcamera_interface.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

const int T_PCLK_PER_TP = 2;
const int TP_PER_LINE = 784;
const int PCLK_PER_LINE = TP_PER_LINE * T_PCLK_PER_TP;
const int VISIBLE_PIXELS = 640;
const int PCLK_PER_PIXEL = 2; // 2 bytes per pixel
const int ACTIVE_PCLK = VISIBLE_PIXELS * PCLK_PER_PIXEL;
const int INACTIVE_PCLK = PCLK_PER_LINE - ACTIVE_PCLK;
const int NUM_LINES = 510;
const int ACTIVE_LINES = 480;

int main() {
    Verilated::traceEverOn(true);
    Vcamera_interface* dut = new Vcamera_interface;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("dump.vcd");

    dut->pclk = 0;
    dut->d = 0;
    dut->href = 0;
    dut->vsync = 0;
    dut->shutter_raw = 0;

    int cycle = 0;
    auto toggle_pclk = [&](int clk_count) {
        for (int i = 0; i < clk_count; ++i) {
            cycle++;
            dut->pclk = 0;
            dut->eval();
            tfp->dump(cycle * 2);

            // On falling edge
            dut->pclk = 1;
            dut->eval();
            tfp->dump(cycle * 2 + 1);
        }
    };

    // Trigger shutter for 1 falling edge
    dut->shutter_raw = 1;
    toggle_pclk(15);
    dut->shutter_raw = 0;

    // VSYNC high for 3 t_LINE = 3 * 784 * 2 = 4704 pclk (triggered by falling edge of pclk)
    // Set vsync high on the falling edge of pclk
    toggle_pclk(1); // First falling edge of pclk
    dut->vsync = 1; // VSYNC rises at falling edge of pclk
    toggle_pclk(4703); // Stay high for the remaining time to complete 3 * t_LINE

    // VSYNC low, wait 17 t_LINE = 26656 pclk
    dut->vsync = 0;
    toggle_pclk(26656);

    // Image capture loop (480 lines)
    for (int row = 0; row < ACTIVE_LINES; ++row) {
        dut->href = 1;
        bool byte_toggle = true;

        for (int i = 0; i < ACTIVE_PCLK; ++i) {
            // Send alternating byte values
            dut->d = byte_toggle ? 0x7C : 0x00;
            byte_toggle = !byte_toggle;
            toggle_pclk(1);
        }

        // href low for rest of line (padding)
        dut->href = 0;
        for (int i = 0; i < INACTIVE_PCLK; ++i)
            toggle_pclk(1);
    }

    // VSYNC rise after 10 more lines
    toggle_pclk(PCLK_PER_LINE * 10);
    toggle_pclk(1); // VSYNC rise occu;./lrs on falling edge of pclk
    dut->vsync = 1;
    toggle_pclk(PCLK_PER_LINE * 3);
    dut->vsync = 0;

    tfp->close();
    delete dut;
    return 0;
}
