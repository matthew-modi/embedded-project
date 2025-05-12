// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcamera_interface__Syms.h"


//======================

void Vcamera_interface::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vcamera_interface::traceInit, &Vcamera_interface::traceFull, &Vcamera_interface::traceChg, this);
}
void Vcamera_interface::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vcamera_interface* t = (Vcamera_interface*)userthis;
    Vcamera_interface__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vcamera_interface::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vcamera_interface* t = (Vcamera_interface*)userthis;
    Vcamera_interface__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vcamera_interface::traceInitThis(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vcamera_interface::traceFullThis(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vcamera_interface::traceInitThis__1(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+129,"href", false,-1);
        vcdp->declBit(c+137,"vsync", false,-1);
        vcdp->declBit(c+145,"pclk", false,-1);
        vcdp->declBus(c+153,"d", false,-1, 7,0);
        vcdp->declBit(c+161,"shutter", false,-1);
        vcdp->declBit(c+169,"empty", false,-1);
        vcdp->declBit(c+177,"fifo_enable", false,-1);
        vcdp->declBus(c+185,"wide_bit_out", false,-1, 31,0);
        vcdp->declBit(c+193,"clk", false,-1);
        vcdp->declBit(c+129,"camera_interface href", false,-1);
        vcdp->declBit(c+137,"camera_interface vsync", false,-1);
        vcdp->declBit(c+145,"camera_interface pclk", false,-1);
        vcdp->declBus(c+153,"camera_interface d", false,-1, 7,0);
        vcdp->declBit(c+161,"camera_interface shutter", false,-1);
        vcdp->declBit(c+169,"camera_interface empty", false,-1);
        vcdp->declBit(c+177,"camera_interface fifo_enable", false,-1);
        vcdp->declBus(c+185,"camera_interface wide_bit_out", false,-1, 31,0);
        vcdp->declBit(c+193,"camera_interface clk", false,-1);
        vcdp->declBus(c+25,"camera_interface state", false,-1, 1,0);
        vcdp->declBus(c+33,"camera_interface col_count", false,-1, 10,0);
        vcdp->declBus(c+41,"camera_interface row_count", false,-1, 8,0);
        vcdp->declBus(c+17,"camera_interface clk_count", false,-1, 2,0);
        vcdp->declBus(c+9,"camera_interface q", false,-1, 7,0);
        vcdp->declBit(c+1,"camera_interface write_enable", false,-1);
        vcdp->declBit(c+49,"camera_interface prev_vsync", false,-1);
        vcdp->declBit(c+137,"camera_interface curr_vsync", false,-1);
        vcdp->declBit(c+57,"camera_interface ready", false,-1);
        vcdp->declBit(c+1,"camera_interface write_trigger", false,-1);
        vcdp->declBit(c+145,"camera_interface uut0 clk", false,-1);
        vcdp->declBit(c+169,"camera_interface uut0 rst", false,-1);
        vcdp->declBit(c+129,"camera_interface uut0 en", false,-1);
        vcdp->declBit(c+201,"camera_interface uut0 d", false,-1);
        vcdp->declBit(c+65,"camera_interface uut0 q", false,-1);
        vcdp->declBit(c+145,"camera_interface uut1 clk", false,-1);
        vcdp->declBit(c+169,"camera_interface uut1 rst", false,-1);
        vcdp->declBit(c+129,"camera_interface uut1 en", false,-1);
        vcdp->declBit(c+209,"camera_interface uut1 d", false,-1);
        vcdp->declBit(c+73,"camera_interface uut1 q", false,-1);
        vcdp->declBit(c+145,"camera_interface uut2 clk", false,-1);
        vcdp->declBit(c+169,"camera_interface uut2 rst", false,-1);
        vcdp->declBit(c+129,"camera_interface uut2 en", false,-1);
        vcdp->declBit(c+217,"camera_interface uut2 d", false,-1);
        vcdp->declBit(c+81,"camera_interface uut2 q", false,-1);
        vcdp->declBit(c+145,"camera_interface uut3 clk", false,-1);
        vcdp->declBit(c+169,"camera_interface uut3 rst", false,-1);
        vcdp->declBit(c+129,"camera_interface uut3 en", false,-1);
        vcdp->declBit(c+225,"camera_interface uut3 d", false,-1);
        vcdp->declBit(c+89,"camera_interface uut3 q", false,-1);
        vcdp->declBit(c+145,"camera_interface uut4 clk", false,-1);
        vcdp->declBit(c+169,"camera_interface uut4 rst", false,-1);
        vcdp->declBit(c+129,"camera_interface uut4 en", false,-1);
        vcdp->declBit(c+233,"camera_interface uut4 d", false,-1);
        vcdp->declBit(c+97,"camera_interface uut4 q", false,-1);
        vcdp->declBit(c+145,"camera_interface uut5 clk", false,-1);
        vcdp->declBit(c+169,"camera_interface uut5 rst", false,-1);
        vcdp->declBit(c+129,"camera_interface uut5 en", false,-1);
        vcdp->declBit(c+241,"camera_interface uut5 d", false,-1);
        vcdp->declBit(c+105,"camera_interface uut5 q", false,-1);
        vcdp->declBit(c+145,"camera_interface uut6 clk", false,-1);
        vcdp->declBit(c+169,"camera_interface uut6 rst", false,-1);
        vcdp->declBit(c+129,"camera_interface uut6 en", false,-1);
        vcdp->declBit(c+249,"camera_interface uut6 d", false,-1);
        vcdp->declBit(c+113,"camera_interface uut6 q", false,-1);
        vcdp->declBit(c+145,"camera_interface uut7 clk", false,-1);
        vcdp->declBit(c+169,"camera_interface uut7 rst", false,-1);
        vcdp->declBit(c+129,"camera_interface uut7 en", false,-1);
        vcdp->declBit(c+257,"camera_interface uut7 d", false,-1);
        vcdp->declBit(c+121,"camera_interface uut7 q", false,-1);
    }
}

void Vcamera_interface::traceFullThis__1(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->camera_interface__DOT__write_enable));
        vcdp->fullBus(c+9,(vlTOPp->camera_interface__DOT__q),8);
        vcdp->fullBus(c+17,(vlTOPp->camera_interface__DOT__clk_count),3);
        vcdp->fullBus(c+25,(vlTOPp->camera_interface__DOT__state),2);
        vcdp->fullBus(c+33,(vlTOPp->camera_interface__DOT__col_count),11);
        vcdp->fullBus(c+41,(vlTOPp->camera_interface__DOT__row_count),9);
        vcdp->fullBit(c+49,(vlTOPp->camera_interface__DOT__prev_vsync));
        vcdp->fullBit(c+57,(vlTOPp->camera_interface__DOT__ready));
        vcdp->fullBit(c+65,(vlTOPp->camera_interface__DOT____Vcellout__uut0__q));
        vcdp->fullBit(c+73,(vlTOPp->camera_interface__DOT____Vcellout__uut1__q));
        vcdp->fullBit(c+81,(vlTOPp->camera_interface__DOT____Vcellout__uut2__q));
        vcdp->fullBit(c+89,(vlTOPp->camera_interface__DOT____Vcellout__uut3__q));
        vcdp->fullBit(c+97,(vlTOPp->camera_interface__DOT____Vcellout__uut4__q));
        vcdp->fullBit(c+105,(vlTOPp->camera_interface__DOT____Vcellout__uut5__q));
        vcdp->fullBit(c+113,(vlTOPp->camera_interface__DOT____Vcellout__uut6__q));
        vcdp->fullBit(c+121,(vlTOPp->camera_interface__DOT____Vcellout__uut7__q));
        vcdp->fullBit(c+129,(vlTOPp->href));
        vcdp->fullBit(c+137,(vlTOPp->vsync));
        vcdp->fullBit(c+145,(vlTOPp->pclk));
        vcdp->fullBus(c+153,(vlTOPp->d),8);
        vcdp->fullBit(c+161,(vlTOPp->shutter));
        vcdp->fullBit(c+169,(vlTOPp->empty));
        vcdp->fullBit(c+177,(vlTOPp->fifo_enable));
        vcdp->fullBus(c+185,(vlTOPp->wide_bit_out),32);
        vcdp->fullBit(c+193,(vlTOPp->clk));
        vcdp->fullBit(c+201,((1U & (IData)(vlTOPp->d))));
        vcdp->fullBit(c+209,((1U & ((IData)(vlTOPp->d) 
                                    >> 1U))));
        vcdp->fullBit(c+217,((1U & ((IData)(vlTOPp->d) 
                                    >> 2U))));
        vcdp->fullBit(c+225,((1U & ((IData)(vlTOPp->d) 
                                    >> 3U))));
        vcdp->fullBit(c+233,((1U & ((IData)(vlTOPp->d) 
                                    >> 4U))));
        vcdp->fullBit(c+241,((1U & ((IData)(vlTOPp->d) 
                                    >> 5U))));
        vcdp->fullBit(c+249,((1U & ((IData)(vlTOPp->d) 
                                    >> 6U))));
        vcdp->fullBit(c+257,((1U & ((IData)(vlTOPp->d) 
                                    >> 7U))));
    }
}
