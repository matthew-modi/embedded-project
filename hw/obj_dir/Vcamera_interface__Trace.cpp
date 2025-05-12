// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcamera_interface__Syms.h"


//======================

void Vcamera_interface::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vcamera_interface* t = (Vcamera_interface*)userthis;
    Vcamera_interface__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vcamera_interface::traceChgThis(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 4U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((8U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((0x10U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vcamera_interface::traceChgThis__2(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->camera_interface__DOT__write_enable));
    }
}

void Vcamera_interface::traceChgThis__3(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+9,(vlTOPp->camera_interface__DOT__q),8);
    }
}

void Vcamera_interface::traceChgThis__4(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+17,(vlTOPp->camera_interface__DOT__clk_count),3);
    }
}

void Vcamera_interface::traceChgThis__5(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+25,(vlTOPp->camera_interface__DOT__state),2);
        vcdp->chgBus(c+33,(vlTOPp->camera_interface__DOT__col_count),11);
        vcdp->chgBus(c+41,(vlTOPp->camera_interface__DOT__row_count),9);
        vcdp->chgBit(c+49,(vlTOPp->camera_interface__DOT__prev_vsync));
        vcdp->chgBit(c+57,(vlTOPp->camera_interface__DOT__ready));
    }
}

void Vcamera_interface::traceChgThis__6(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+65,(vlTOPp->camera_interface__DOT____Vcellout__uut0__q));
        vcdp->chgBit(c+73,(vlTOPp->camera_interface__DOT____Vcellout__uut1__q));
        vcdp->chgBit(c+81,(vlTOPp->camera_interface__DOT____Vcellout__uut2__q));
        vcdp->chgBit(c+89,(vlTOPp->camera_interface__DOT____Vcellout__uut3__q));
        vcdp->chgBit(c+97,(vlTOPp->camera_interface__DOT____Vcellout__uut4__q));
        vcdp->chgBit(c+105,(vlTOPp->camera_interface__DOT____Vcellout__uut5__q));
        vcdp->chgBit(c+113,(vlTOPp->camera_interface__DOT____Vcellout__uut6__q));
        vcdp->chgBit(c+121,(vlTOPp->camera_interface__DOT____Vcellout__uut7__q));
    }
}

void Vcamera_interface::traceChgThis__7(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+129,(vlTOPp->href));
        vcdp->chgBit(c+137,(vlTOPp->vsync));
        vcdp->chgBit(c+145,(vlTOPp->pclk));
        vcdp->chgBus(c+153,(vlTOPp->d),8);
        vcdp->chgBit(c+161,(vlTOPp->shutter));
        vcdp->chgBit(c+169,(vlTOPp->empty));
        vcdp->chgBit(c+177,(vlTOPp->fifo_enable));
        vcdp->chgBus(c+185,(vlTOPp->wide_bit_out),32);
        vcdp->chgBit(c+193,(vlTOPp->clk));
        vcdp->chgBit(c+201,((1U & (IData)(vlTOPp->d))));
        vcdp->chgBit(c+209,((1U & ((IData)(vlTOPp->d) 
                                   >> 1U))));
        vcdp->chgBit(c+217,((1U & ((IData)(vlTOPp->d) 
                                   >> 2U))));
        vcdp->chgBit(c+225,((1U & ((IData)(vlTOPp->d) 
                                   >> 3U))));
        vcdp->chgBit(c+233,((1U & ((IData)(vlTOPp->d) 
                                   >> 4U))));
        vcdp->chgBit(c+241,((1U & ((IData)(vlTOPp->d) 
                                   >> 5U))));
        vcdp->chgBit(c+249,((1U & ((IData)(vlTOPp->d) 
                                   >> 6U))));
        vcdp->chgBit(c+257,((1U & ((IData)(vlTOPp->d) 
                                   >> 7U))));
    }
}
