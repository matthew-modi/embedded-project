// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcamera_interface__Syms.h"


void Vcamera_interface::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vcamera_interface__Syms* __restrict vlSymsp = static_cast<Vcamera_interface__Syms*>(userp);
    Vcamera_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vcamera_interface::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vcamera_interface__Syms* __restrict vlSymsp = static_cast<Vcamera_interface__Syms*>(userp);
    Vcamera_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk));
        tracep->chgBit(oldp+1,(vlTOPp->reset));
        tracep->chgCData(oldp+2,(vlTOPp->d),8);
        tracep->chgBit(oldp+3,(vlTOPp->href));
        tracep->chgBit(oldp+4,(vlTOPp->vsync));
        tracep->chgBit(oldp+5,(vlTOPp->hsync));
        tracep->chgCData(oldp+6,(vlTOPp->q),8);
    }
}

void Vcamera_interface::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vcamera_interface__Syms* __restrict vlSymsp = static_cast<Vcamera_interface__Syms*>(userp);
    Vcamera_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
