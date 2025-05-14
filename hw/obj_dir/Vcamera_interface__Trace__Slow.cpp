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
        vcdp->declBit(c+185,"reset", false,-1);
        vcdp->declBit(c+193,"href", false,-1);
        vcdp->declBit(c+201,"vsync", false,-1);
        vcdp->declBit(c+209,"pclk", false,-1);
        vcdp->declBus(c+217,"d", false,-1, 7,0);
        vcdp->declBit(c+225,"shutter_raw", false,-1);
        vcdp->declBit(c+233,"fifo_enable", false,-1);
        vcdp->declBus(c+241,"wide_bit_out", false,-1, 31,0);
        vcdp->declBit(c+185,"camera_interface reset", false,-1);
        vcdp->declBit(c+193,"camera_interface href", false,-1);
        vcdp->declBit(c+201,"camera_interface vsync", false,-1);
        vcdp->declBit(c+209,"camera_interface pclk", false,-1);
        vcdp->declBus(c+217,"camera_interface d", false,-1, 7,0);
        vcdp->declBit(c+225,"camera_interface shutter_raw", false,-1);
        vcdp->declBit(c+233,"camera_interface fifo_enable", false,-1);
        vcdp->declBus(c+241,"camera_interface wide_bit_out", false,-1, 31,0);
        vcdp->declBus(c+145,"camera_interface state", false,-1, 1,0);
        vcdp->declBus(c+153,"camera_interface col_count", false,-1, 10,0);
        vcdp->declBus(c+161,"camera_interface row_count", false,-1, 8,0);
        vcdp->declBus(c+73,"camera_interface clk_count", false,-1, 2,0);
        vcdp->declBus(c+1,"camera_interface q", false,-1, 7,0);
        vcdp->declBit(c+9,"camera_interface shutter", false,-1);
        vcdp->declBit(c+65,"camera_interface write_enable", false,-1);
        vcdp->declBit(c+169,"camera_interface prev_vsync", false,-1);
        vcdp->declBit(c+201,"camera_interface curr_vsync", false,-1);
        vcdp->declBit(c+65,"camera_interface write_trigger", false,-1);
        vcdp->declBit(c+177,"camera_interface rst", false,-1);
        vcdp->declBit(c+209,"camera_interface uut0 clk", false,-1);
        vcdp->declBit(c+177,"camera_interface uut0 rst", false,-1);
        vcdp->declBit(c+193,"camera_interface uut0 en", false,-1);
        vcdp->declBit(c+249,"camera_interface uut0 d", false,-1);
        vcdp->declBit(c+81,"camera_interface uut0 q", false,-1);
        vcdp->declBit(c+209,"camera_interface uut1 clk", false,-1);
        vcdp->declBit(c+177,"camera_interface uut1 rst", false,-1);
        vcdp->declBit(c+193,"camera_interface uut1 en", false,-1);
        vcdp->declBit(c+257,"camera_interface uut1 d", false,-1);
        vcdp->declBit(c+89,"camera_interface uut1 q", false,-1);
        vcdp->declBit(c+209,"camera_interface uut2 clk", false,-1);
        vcdp->declBit(c+177,"camera_interface uut2 rst", false,-1);
        vcdp->declBit(c+193,"camera_interface uut2 en", false,-1);
        vcdp->declBit(c+265,"camera_interface uut2 d", false,-1);
        vcdp->declBit(c+97,"camera_interface uut2 q", false,-1);
        vcdp->declBit(c+209,"camera_interface uut3 clk", false,-1);
        vcdp->declBit(c+177,"camera_interface uut3 rst", false,-1);
        vcdp->declBit(c+193,"camera_interface uut3 en", false,-1);
        vcdp->declBit(c+273,"camera_interface uut3 d", false,-1);
        vcdp->declBit(c+105,"camera_interface uut3 q", false,-1);
        vcdp->declBit(c+209,"camera_interface uut4 clk", false,-1);
        vcdp->declBit(c+177,"camera_interface uut4 rst", false,-1);
        vcdp->declBit(c+193,"camera_interface uut4 en", false,-1);
        vcdp->declBit(c+281,"camera_interface uut4 d", false,-1);
        vcdp->declBit(c+113,"camera_interface uut4 q", false,-1);
        vcdp->declBit(c+209,"camera_interface uut5 clk", false,-1);
        vcdp->declBit(c+177,"camera_interface uut5 rst", false,-1);
        vcdp->declBit(c+193,"camera_interface uut5 en", false,-1);
        vcdp->declBit(c+289,"camera_interface uut5 d", false,-1);
        vcdp->declBit(c+121,"camera_interface uut5 q", false,-1);
        vcdp->declBit(c+209,"camera_interface uut6 clk", false,-1);
        vcdp->declBit(c+177,"camera_interface uut6 rst", false,-1);
        vcdp->declBit(c+193,"camera_interface uut6 en", false,-1);
        vcdp->declBit(c+297,"camera_interface uut6 d", false,-1);
        vcdp->declBit(c+129,"camera_interface uut6 q", false,-1);
        vcdp->declBit(c+209,"camera_interface uut7 clk", false,-1);
        vcdp->declBit(c+177,"camera_interface uut7 rst", false,-1);
        vcdp->declBit(c+193,"camera_interface uut7 en", false,-1);
        vcdp->declBit(c+305,"camera_interface uut7 d", false,-1);
        vcdp->declBit(c+137,"camera_interface uut7 q", false,-1);
        vcdp->declBit(c+225,"camera_interface uut8 pb_1", false,-1);
        vcdp->declBit(c+209,"camera_interface uut8 clk", false,-1);
        vcdp->declBit(c+9,"camera_interface uut8 pb_out", false,-1);
        vcdp->declBit(c+17,"camera_interface uut8 slow_clk_en", false,-1);
        vcdp->declBit(c+25,"camera_interface uut8 Q1", false,-1);
        vcdp->declBit(c+33,"camera_interface uut8 Q2", false,-1);
        vcdp->declBit(c+41,"camera_interface uut8 Q2_bar", false,-1);
        vcdp->declBit(c+49,"camera_interface uut8 Q0", false,-1);
        vcdp->declBit(c+209,"camera_interface uut8 u1 clk", false,-1);
        vcdp->declBit(c+17,"camera_interface uut8 u1 slow_clk_en", false,-1);
        vcdp->declBus(c+57,"camera_interface uut8 u1 counter", false,-1, 3,0);
        vcdp->declBit(c+209,"camera_interface uut8 d0 DFF_CLOCK", false,-1);
        vcdp->declBit(c+17,"camera_interface uut8 d0 clock_enable", false,-1);
        vcdp->declBit(c+225,"camera_interface uut8 d0 D", false,-1);
        vcdp->declBit(c+49,"camera_interface uut8 d0 Q", false,-1);
        vcdp->declBit(c+209,"camera_interface uut8 d1 DFF_CLOCK", false,-1);
        vcdp->declBit(c+17,"camera_interface uut8 d1 clock_enable", false,-1);
        vcdp->declBit(c+49,"camera_interface uut8 d1 D", false,-1);
        vcdp->declBit(c+25,"camera_interface uut8 d1 Q", false,-1);
        vcdp->declBit(c+209,"camera_interface uut8 d2 DFF_CLOCK", false,-1);
        vcdp->declBit(c+17,"camera_interface uut8 d2 clock_enable", false,-1);
        vcdp->declBit(c+25,"camera_interface uut8 d2 D", false,-1);
        vcdp->declBit(c+33,"camera_interface uut8 d2 Q", false,-1);
    }
}

void Vcamera_interface::traceFullThis__1(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->camera_interface__DOT__q),8);
        vcdp->fullBit(c+9,((((IData)(vlTOPp->camera_interface__DOT__uut8__DOT__Q1) 
                             & (~ (IData)(vlTOPp->camera_interface__DOT__uut8__DOT__Q2))) 
                            & (9U == (IData)(vlTOPp->camera_interface__DOT__uut8__DOT__u1__DOT__counter)))));
        vcdp->fullBit(c+17,((9U == (IData)(vlTOPp->camera_interface__DOT__uut8__DOT__u1__DOT__counter))));
        vcdp->fullBit(c+25,(vlTOPp->camera_interface__DOT__uut8__DOT__Q1));
        vcdp->fullBit(c+33,(vlTOPp->camera_interface__DOT__uut8__DOT__Q2));
        vcdp->fullBit(c+41,((1U & (~ (IData)(vlTOPp->camera_interface__DOT__uut8__DOT__Q2)))));
        vcdp->fullBit(c+49,(vlTOPp->camera_interface__DOT__uut8__DOT__Q0));
        vcdp->fullBus(c+57,(vlTOPp->camera_interface__DOT__uut8__DOT__u1__DOT__counter),4);
        vcdp->fullBit(c+65,(vlTOPp->camera_interface__DOT__write_enable));
        vcdp->fullBus(c+73,(vlTOPp->camera_interface__DOT__clk_count),3);
        vcdp->fullBit(c+81,(vlTOPp->camera_interface__DOT____Vcellout__uut0__q));
        vcdp->fullBit(c+89,(vlTOPp->camera_interface__DOT____Vcellout__uut1__q));
        vcdp->fullBit(c+97,(vlTOPp->camera_interface__DOT____Vcellout__uut2__q));
        vcdp->fullBit(c+105,(vlTOPp->camera_interface__DOT____Vcellout__uut3__q));
        vcdp->fullBit(c+113,(vlTOPp->camera_interface__DOT____Vcellout__uut4__q));
        vcdp->fullBit(c+121,(vlTOPp->camera_interface__DOT____Vcellout__uut5__q));
        vcdp->fullBit(c+129,(vlTOPp->camera_interface__DOT____Vcellout__uut6__q));
        vcdp->fullBit(c+137,(vlTOPp->camera_interface__DOT____Vcellout__uut7__q));
        vcdp->fullBus(c+145,(vlTOPp->camera_interface__DOT__state),2);
        vcdp->fullBus(c+153,(vlTOPp->camera_interface__DOT__col_count),11);
        vcdp->fullBus(c+161,(vlTOPp->camera_interface__DOT__row_count),9);
        vcdp->fullBit(c+169,(vlTOPp->camera_interface__DOT__prev_vsync));
        vcdp->fullBit(c+177,(vlTOPp->camera_interface__DOT__rst));
        vcdp->fullBit(c+185,(vlTOPp->reset));
        vcdp->fullBit(c+193,(vlTOPp->href));
        vcdp->fullBit(c+201,(vlTOPp->vsync));
        vcdp->fullBit(c+209,(vlTOPp->pclk));
        vcdp->fullBus(c+217,(vlTOPp->d),8);
        vcdp->fullBit(c+225,(vlTOPp->shutter_raw));
        vcdp->fullBit(c+233,(vlTOPp->fifo_enable));
        vcdp->fullBus(c+241,(vlTOPp->wide_bit_out),32);
        vcdp->fullBit(c+249,((1U & (IData)(vlTOPp->d))));
        vcdp->fullBit(c+257,((1U & ((IData)(vlTOPp->d) 
                                    >> 1U))));
        vcdp->fullBit(c+265,((1U & ((IData)(vlTOPp->d) 
                                    >> 2U))));
        vcdp->fullBit(c+273,((1U & ((IData)(vlTOPp->d) 
                                    >> 3U))));
        vcdp->fullBit(c+281,((1U & ((IData)(vlTOPp->d) 
                                    >> 4U))));
        vcdp->fullBit(c+289,((1U & ((IData)(vlTOPp->d) 
                                    >> 5U))));
        vcdp->fullBit(c+297,((1U & ((IData)(vlTOPp->d) 
                                    >> 6U))));
        vcdp->fullBit(c+305,((1U & ((IData)(vlTOPp->d) 
                                    >> 7U))));
    }
}
