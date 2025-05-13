// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vvga_interface__Syms.h"


void Vvga_interface::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vvga_interface__Syms* __restrict vlSymsp = static_cast<Vvga_interface__Syms*>(userp);
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vvga_interface::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vvga_interface__Syms* __restrict vlSymsp = static_cast<Vvga_interface__Syms*>(userp);
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->pclk));
        tracep->chgBit(oldp+1,(vlTOPp->reset));
        tracep->chgBit(oldp+2,(vlTOPp->cam_href));
        tracep->chgBit(oldp+3,(vlTOPp->cam_vsync));
        tracep->chgCData(oldp+4,(vlTOPp->cam_data),8);
        tracep->chgBit(oldp+5,(vlTOPp->VGA_CLK));
        tracep->chgBit(oldp+6,(vlTOPp->VGA_HS));
        tracep->chgBit(oldp+7,(vlTOPp->VGA_VS));
        tracep->chgBit(oldp+8,(vlTOPp->VGA_BLANK_n));
        tracep->chgBit(oldp+9,(vlTOPp->VGA_SYNC_n));
        tracep->chgCData(oldp+10,(vlTOPp->VGA_R),8);
        tracep->chgCData(oldp+11,(vlTOPp->VGA_G),8);
        tracep->chgCData(oldp+12,(vlTOPp->VGA_B),8);
        tracep->chgBit(oldp+13,(vlTOPp->vga_interface__DOT__byte_flag));
        tracep->chgSData(oldp+14,(vlTOPp->vga_interface__DOT__pix16),16);
    }
}

void Vvga_interface::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vvga_interface__Syms* __restrict vlSymsp = static_cast<Vvga_interface__Syms*>(userp);
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
