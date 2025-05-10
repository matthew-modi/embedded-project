// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcamera_interface.h for the primary calling header

#include "Vcamera_interface.h"
#include "Vcamera_interface__Syms.h"

//==========

VL_CTOR_IMP(Vcamera_interface) {
    Vcamera_interface__Syms* __restrict vlSymsp = __VlSymsp = new Vcamera_interface__Syms(this, name());
    Vcamera_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcamera_interface::__Vconfigure(Vcamera_interface__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vcamera_interface::~Vcamera_interface() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vcamera_interface::_eval_initial(Vcamera_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_eval_initial\n"); );
    Vcamera_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vcamera_interface::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::final\n"); );
    // Variables
    Vcamera_interface__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcamera_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcamera_interface::_eval_settle(Vcamera_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_eval_settle\n"); );
    Vcamera_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcamera_interface::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    d = VL_RAND_RESET_I(8);
    href = VL_RAND_RESET_I(1);
    vsync = VL_RAND_RESET_I(1);
    hsync = VL_RAND_RESET_I(1);
    q = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
