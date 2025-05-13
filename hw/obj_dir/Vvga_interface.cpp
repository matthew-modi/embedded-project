// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvga_interface.h for the primary calling header

#include "Vvga_interface.h"
#include "Vvga_interface__Syms.h"

//==========

void Vvga_interface::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vvga_interface::eval\n"); );
    Vvga_interface__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vga_interface.sv", 5, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vvga_interface::_eval_initial_loop(Vvga_interface__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("vga_interface.sv", 5, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vvga_interface::_combo__TOP__2(Vvga_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_interface::_combo__TOP__2\n"); );
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->VGA_CLK = vlTOPp->pclk;
    vlTOPp->VGA_HS = vlTOPp->cam_href;
    vlTOPp->VGA_VS = vlTOPp->cam_vsync;
    vlTOPp->VGA_BLANK_n = vlTOPp->cam_href;
}

VL_INLINE_OPT void Vvga_interface::_sequent__TOP__4(Vvga_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_interface::_sequent__TOP__4\n"); );
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__vga_interface__DOT__byte_flag;
    // Body
    __Vdly__vga_interface__DOT__byte_flag = vlTOPp->vga_interface__DOT__byte_flag;
    if (vlTOPp->reset) {
        __Vdly__vga_interface__DOT__byte_flag = 0U;
        vlTOPp->vga_interface__DOT__pix16 = 0U;
    } else {
        if (vlTOPp->cam_href) {
            vlTOPp->vga_interface__DOT__pix16 = ((IData)(vlTOPp->vga_interface__DOT__byte_flag)
                                                  ? 
                                                 ((0xff00U 
                                                   & (IData)(vlTOPp->vga_interface__DOT__pix16)) 
                                                  | (IData)(vlTOPp->cam_data))
                                                  : 
                                                 ((0xffU 
                                                   & (IData)(vlTOPp->vga_interface__DOT__pix16)) 
                                                  | ((IData)(vlTOPp->cam_data) 
                                                     << 8U)));
            __Vdly__vga_interface__DOT__byte_flag = 
                (1U & (~ (IData)(vlTOPp->vga_interface__DOT__byte_flag)));
        } else {
            __Vdly__vga_interface__DOT__byte_flag = 0U;
        }
    }
    vlTOPp->vga_interface__DOT__byte_flag = __Vdly__vga_interface__DOT__byte_flag;
    vlTOPp->VGA_R = (0xf8U & ((IData)(vlTOPp->vga_interface__DOT__pix16) 
                              >> 8U));
    vlTOPp->VGA_G = (0xfcU & ((IData)(vlTOPp->vga_interface__DOT__pix16) 
                              >> 3U));
    vlTOPp->VGA_B = (0xf8U & ((IData)(vlTOPp->vga_interface__DOT__pix16) 
                              << 3U));
}

void Vvga_interface::_eval(Vvga_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_interface::_eval\n"); );
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if ((((IData)(vlTOPp->pclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__pclk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__pclk = vlTOPp->pclk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

VL_INLINE_OPT QData Vvga_interface::_change_request(Vvga_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_interface::_change_request\n"); );
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vvga_interface::_change_request_1(Vvga_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_interface::_change_request_1\n"); );
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vvga_interface::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_interface::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((pclk & 0xfeU))) {
        Verilated::overWidthError("pclk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((cam_href & 0xfeU))) {
        Verilated::overWidthError("cam_href");}
    if (VL_UNLIKELY((cam_vsync & 0xfeU))) {
        Verilated::overWidthError("cam_vsync");}
}
#endif  // VL_DEBUG
