#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main() {
    Verilated::traceEverOn(true);
    Vtop* dut = new Vtop;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("dump.vcd");

    dut->reset = 1;
    dut->d = 0;

    for (int i = 0; i < 100; ++i) {


        //Rising edge
        dut->clk = 1;
        dut->eval();
        tfp->dump(i * 2);

        if (i < 10) {
            dut->reset = 1;
        } else {
            dut->reset = 0;
        }

        if ( i > 20) {
            dut->d = 1;
        }

        //Falling edge
        dut->clk = 0;
        dut->eval();
        tfp->dump(i * 2 + 1);
    }

    tfp->close();
    delete dut;
    return 0;
}
