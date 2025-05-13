// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvga_interface.h for the primary calling header

#include "Vvga_interface.h"
#include "Vvga_interface__Syms.h"

//==========

VL_CTOR_IMP(Vvga_interface) {
    Vvga_interface__Syms* __restrict vlSymsp = __VlSymsp = new Vvga_interface__Syms(this, name());
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vvga_interface::__Vconfigure(Vvga_interface__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vvga_interface::~Vvga_interface() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vvga_interface::_initial__TOP__1(Vvga_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_interface::_initial__TOP__1\n"); );
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->VGA_SYNC_n = 1U;
}

void Vvga_interface::_settle__TOP__3(Vvga_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_interface::_settle__TOP__3\n"); );
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->VGA_CLK = vlTOPp->pclk;
    vlTOPp->VGA_HS = vlTOPp->cam_href;
    vlTOPp->VGA_VS = vlTOPp->cam_vsync;
    vlTOPp->VGA_BLANK_n = vlTOPp->cam_href;
    vlTOPp->VGA_R = (0xf8U & ((IData)(vlTOPp->vga_interface__DOT__pix16) 
                              >> 8U));
    vlTOPp->VGA_G = (0xfcU & ((IData)(vlTOPp->vga_interface__DOT__pix16) 
                              >> 3U));
    vlTOPp->VGA_B = (0xf8U & ((IData)(vlTOPp->vga_interface__DOT__pix16) 
                              << 3U));
}

void Vvga_interface::_eval_initial(Vvga_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_interface::_eval_initial\n"); );
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__pclk = vlTOPp->pclk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vvga_interface::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_interface::final\n"); );
    // Variables
    Vvga_interface__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vvga_interface::_eval_settle(Vvga_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_interface::_eval_settle\n"); );
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vvga_interface::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_interface::_ctor_var_reset\n"); );
    // Body
    pclk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    cam_href = VL_RAND_RESET_I(1);
    cam_vsync = VL_RAND_RESET_I(1);
    cam_data = VL_RAND_RESET_I(8);
    VGA_CLK = VL_RAND_RESET_I(1);
    VGA_HS = VL_RAND_RESET_I(1);
    VGA_VS = VL_RAND_RESET_I(1);
    VGA_BLANK_n = VL_RAND_RESET_I(1);
    VGA_SYNC_n = VL_RAND_RESET_I(1);
    VGA_R = VL_RAND_RESET_I(8);
    VGA_G = VL_RAND_RESET_I(8);
    VGA_B = VL_RAND_RESET_I(8);
    vga_interface__DOT__byte_flag = VL_RAND_RESET_I(1);
    vga_interface__DOT__pix16 = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
