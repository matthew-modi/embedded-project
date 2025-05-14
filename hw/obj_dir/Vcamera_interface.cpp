// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcamera_interface.h for the primary calling header

#include "Vcamera_interface.h"
#include "Vcamera_interface__Syms.h"

//==========

VL_CTOR_IMP(Vcamera_interface) {
    Vcamera_interface__Syms* __restrict vlSymsp = __VlSymsp = new Vcamera_interface__Syms(this, name());
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcamera_interface::__Vconfigure(Vcamera_interface__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vcamera_interface::~Vcamera_interface() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vcamera_interface::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcamera_interface::eval\n"); );
    Vcamera_interface__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("camera_interface.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcamera_interface::_eval_initial_loop(Vcamera_interface__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("camera_interface.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vcamera_interface::_sequent__TOP__1(Vcamera_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_sequent__TOP__1\n"); );
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*2:0*/ __Vdly__camera_interface__DOT__clk_count;
    // Body
    vlTOPp->__Vdly__camera_interface__DOT__uut8__DOT__u1__DOT__counter 
        = vlTOPp->camera_interface__DOT__uut8__DOT__u1__DOT__counter;
    __Vdly__camera_interface__DOT__clk_count = vlTOPp->camera_interface__DOT__clk_count;
    vlTOPp->__Vdly__camera_interface__DOT__col_count 
        = vlTOPp->camera_interface__DOT__col_count;
    vlTOPp->__Vdly__camera_interface__DOT__state = vlTOPp->camera_interface__DOT__state;
    vlTOPp->__Vdly__camera_interface__DOT__row_count 
        = vlTOPp->camera_interface__DOT__row_count;
    vlTOPp->__Vdly__camera_interface__DOT__uut8__DOT__u1__DOT__counter 
        = ((9U == (IData)(vlTOPp->camera_interface__DOT__uut8__DOT__u1__DOT__counter))
            ? 0U : (0xfU & ((IData)(1U) + (IData)(vlTOPp->camera_interface__DOT__uut8__DOT__u1__DOT__counter))));
    if ((((IData)(vlTOPp->camera_interface__DOT__write_enable) 
          & (3U == (IData)(vlTOPp->camera_interface__DOT__clk_count))) 
         & (0xefU == (IData)(vlTOPp->camera_interface__DOT__row_count)))) {
        __Vdly__camera_interface__DOT__clk_count = 0U;
    } else {
        if (((4U > (IData)(vlTOPp->camera_interface__DOT__clk_count)) 
             & (IData)(vlTOPp->camera_interface__DOT__write_enable))) {
            __Vdly__camera_interface__DOT__clk_count 
                = (7U & ((IData)(1U) + (IData)(vlTOPp->camera_interface__DOT__clk_count)));
        }
    }
    vlTOPp->camera_interface__DOT__clk_count = __Vdly__camera_interface__DOT__clk_count;
}

VL_INLINE_OPT void Vcamera_interface::_sequent__TOP__2(Vcamera_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_sequent__TOP__2\n"); );
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->camera_interface__DOT__write_enable) 
         & (0U == (IData)(vlTOPp->camera_interface__DOT__clk_count)))) {
        vlTOPp->fifo_enable = 0U;
    } else {
        if (((IData)(vlTOPp->camera_interface__DOT__write_enable) 
             & (1U == (IData)(vlTOPp->camera_interface__DOT__clk_count)))) {
            vlTOPp->fifo_enable = 0U;
        } else {
            if (((IData)(vlTOPp->camera_interface__DOT__write_enable) 
                 & (2U == (IData)(vlTOPp->camera_interface__DOT__clk_count)))) {
                vlTOPp->fifo_enable = 0U;
            } else {
                if (((IData)(vlTOPp->camera_interface__DOT__write_enable) 
                     & (3U == (IData)(vlTOPp->camera_interface__DOT__clk_count)))) {
                    vlTOPp->fifo_enable = 1U;
                }
            }
        }
    }
    if (((IData)(vlTOPp->camera_interface__DOT__write_enable) 
         & (0U == (IData)(vlTOPp->camera_interface__DOT__clk_count)))) {
        vlTOPp->wide_bit_out = ((0xffff00ffU & vlTOPp->wide_bit_out) 
                                | ((IData)(vlTOPp->camera_interface__DOT__q) 
                                   << 8U));
    } else {
        if (((IData)(vlTOPp->camera_interface__DOT__write_enable) 
             & (1U == (IData)(vlTOPp->camera_interface__DOT__clk_count)))) {
            vlTOPp->wide_bit_out = ((0xffffff00U & vlTOPp->wide_bit_out) 
                                    | (IData)(vlTOPp->camera_interface__DOT__q));
        } else {
            if (((IData)(vlTOPp->camera_interface__DOT__write_enable) 
                 & (2U == (IData)(vlTOPp->camera_interface__DOT__clk_count)))) {
                vlTOPp->wide_bit_out = ((0xffffffU 
                                         & vlTOPp->wide_bit_out) 
                                        | ((IData)(vlTOPp->camera_interface__DOT__q) 
                                           << 0x18U));
            } else {
                if (((IData)(vlTOPp->camera_interface__DOT__write_enable) 
                     & (3U == (IData)(vlTOPp->camera_interface__DOT__clk_count)))) {
                    vlTOPp->wide_bit_out = ((0xff00ffffU 
                                             & vlTOPp->wide_bit_out) 
                                            | ((IData)(vlTOPp->camera_interface__DOT__q) 
                                               << 0x10U));
                }
            }
        }
    }
}

VL_INLINE_OPT void Vcamera_interface::_sequent__TOP__3(Vcamera_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_sequent__TOP__3\n"); );
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->camera_interface__DOT__rst) {
        vlTOPp->camera_interface__DOT____Vcellout__uut7__q = 0U;
    } else {
        if (vlTOPp->href) {
            vlTOPp->camera_interface__DOT____Vcellout__uut7__q 
                = (1U & ((IData)(vlTOPp->d) >> 7U));
        }
    }
    if (vlTOPp->camera_interface__DOT__rst) {
        vlTOPp->camera_interface__DOT____Vcellout__uut6__q = 0U;
    } else {
        if (vlTOPp->href) {
            vlTOPp->camera_interface__DOT____Vcellout__uut6__q 
                = (1U & ((IData)(vlTOPp->d) >> 6U));
        }
    }
    if (vlTOPp->camera_interface__DOT__rst) {
        vlTOPp->camera_interface__DOT____Vcellout__uut5__q = 0U;
    } else {
        if (vlTOPp->href) {
            vlTOPp->camera_interface__DOT____Vcellout__uut5__q 
                = (1U & ((IData)(vlTOPp->d) >> 5U));
        }
    }
    if (vlTOPp->camera_interface__DOT__rst) {
        vlTOPp->camera_interface__DOT____Vcellout__uut4__q = 0U;
    } else {
        if (vlTOPp->href) {
            vlTOPp->camera_interface__DOT____Vcellout__uut4__q 
                = (1U & ((IData)(vlTOPp->d) >> 4U));
        }
    }
    if (vlTOPp->camera_interface__DOT__rst) {
        vlTOPp->camera_interface__DOT____Vcellout__uut3__q = 0U;
    } else {
        if (vlTOPp->href) {
            vlTOPp->camera_interface__DOT____Vcellout__uut3__q 
                = (1U & ((IData)(vlTOPp->d) >> 3U));
        }
    }
    if (vlTOPp->camera_interface__DOT__rst) {
        vlTOPp->camera_interface__DOT____Vcellout__uut2__q = 0U;
    } else {
        if (vlTOPp->href) {
            vlTOPp->camera_interface__DOT____Vcellout__uut2__q 
                = (1U & ((IData)(vlTOPp->d) >> 2U));
        }
    }
    if (vlTOPp->camera_interface__DOT__rst) {
        vlTOPp->camera_interface__DOT____Vcellout__uut1__q = 0U;
    } else {
        if (vlTOPp->href) {
            vlTOPp->camera_interface__DOT____Vcellout__uut1__q 
                = (1U & ((IData)(vlTOPp->d) >> 1U));
        }
    }
    if (vlTOPp->camera_interface__DOT__rst) {
        vlTOPp->camera_interface__DOT____Vcellout__uut0__q = 0U;
    } else {
        if (vlTOPp->href) {
            vlTOPp->camera_interface__DOT____Vcellout__uut0__q 
                = (1U & (IData)(vlTOPp->d));
        }
    }
    vlTOPp->camera_interface__DOT__q = ((0x7fU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut7__q) 
                                           << 7U));
    vlTOPp->camera_interface__DOT__q = ((0xbfU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut6__q) 
                                           << 6U));
    vlTOPp->camera_interface__DOT__q = ((0xdfU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut5__q) 
                                           << 5U));
    vlTOPp->camera_interface__DOT__q = ((0xefU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut4__q) 
                                           << 4U));
    vlTOPp->camera_interface__DOT__q = ((0xf7U & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut3__q) 
                                           << 3U));
    vlTOPp->camera_interface__DOT__q = ((0xfbU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut2__q) 
                                           << 2U));
    vlTOPp->camera_interface__DOT__q = ((0xfdU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut1__q) 
                                           << 1U));
    vlTOPp->camera_interface__DOT__q = ((0xfeU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | (IData)(vlTOPp->camera_interface__DOT____Vcellout__uut0__q));
}

void Vcamera_interface::_settle__TOP__4(Vcamera_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_settle__TOP__4\n"); );
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->camera_interface__DOT__q = ((0xfeU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | (IData)(vlTOPp->camera_interface__DOT____Vcellout__uut0__q));
    vlTOPp->camera_interface__DOT__q = ((0xfdU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut1__q) 
                                           << 1U));
    vlTOPp->camera_interface__DOT__q = ((0xfbU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut2__q) 
                                           << 2U));
    vlTOPp->camera_interface__DOT__q = ((0xf7U & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut3__q) 
                                           << 3U));
    vlTOPp->camera_interface__DOT__q = ((0xefU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut4__q) 
                                           << 4U));
    vlTOPp->camera_interface__DOT__q = ((0xdfU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut5__q) 
                                           << 5U));
    vlTOPp->camera_interface__DOT__q = ((0xbfU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut6__q) 
                                           << 6U));
    vlTOPp->camera_interface__DOT__q = ((0x7fU & (IData)(vlTOPp->camera_interface__DOT__q)) 
                                        | ((IData)(vlTOPp->camera_interface__DOT____Vcellout__uut7__q) 
                                           << 7U));
    vlTOPp->camera_interface__DOT__write_enable = (
                                                   ((IData)(vlTOPp->href) 
                                                    & (0xefU 
                                                       == (IData)(vlTOPp->camera_interface__DOT__row_count)))
                                                    ? 1U
                                                    : 0U);
}

void Vcamera_interface::_initial__TOP__5(Vcamera_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_initial__TOP__5\n"); );
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->camera_interface__DOT__uut8__DOT__Q2 = 0U;
    vlTOPp->camera_interface__DOT__uut8__DOT__Q1 = 0U;
    vlTOPp->camera_interface__DOT__uut8__DOT__Q0 = 0U;
    vlTOPp->camera_interface__DOT__uut8__DOT__u1__DOT__counter = 0U;
}

VL_INLINE_OPT void Vcamera_interface::_sequent__TOP__6(Vcamera_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_sequent__TOP__6\n"); );
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->__Vdly__camera_interface__DOT__state = 0U;
        vlTOPp->__Vdly__camera_interface__DOT__col_count = 0U;
        vlTOPp->__Vdly__camera_interface__DOT__row_count = 0U;
        vlTOPp->camera_interface__DOT__prev_vsync = 0U;
        vlTOPp->camera_interface__DOT__rst = 1U;
    } else {
        if (((((IData)(vlTOPp->camera_interface__DOT__uut8__DOT__Q1) 
               & (~ (IData)(vlTOPp->camera_interface__DOT__uut8__DOT__Q2))) 
              & (9U == (IData)(vlTOPp->camera_interface__DOT__uut8__DOT__u1__DOT__counter))) 
             & ((1U > (IData)(vlTOPp->camera_interface__DOT__row_count)) 
                | (0xf0U < (IData)(vlTOPp->camera_interface__DOT__row_count))))) {
            vlTOPp->__Vdly__camera_interface__DOT__state = 0U;
        } else {
            if ((2U & (IData)(vlTOPp->camera_interface__DOT__state))) {
                if ((1U & (IData)(vlTOPp->camera_interface__DOT__state))) {
                    vlTOPp->camera_interface__DOT__prev_vsync 
                        = vlTOPp->vsync;
                } else {
                    if (((0x4ffU > (IData)(vlTOPp->camera_interface__DOT__col_count)) 
                         & (IData)(vlTOPp->href))) {
                        vlTOPp->__Vdly__camera_interface__DOT__col_count 
                            = (0x7ffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->camera_interface__DOT__col_count)));
                    }
                    if (((0x4ffU == (IData)(vlTOPp->camera_interface__DOT__col_count)) 
                         & (IData)(vlTOPp->href))) {
                        vlTOPp->__Vdly__camera_interface__DOT__row_count 
                            = (0x1ffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->camera_interface__DOT__row_count)));
                        vlTOPp->__Vdly__camera_interface__DOT__col_count = 0U;
                    }
                    if (((0xf0U == (IData)(vlTOPp->camera_interface__DOT__row_count)) 
                         & (IData)(vlTOPp->href))) {
                        vlTOPp->__Vdly__camera_interface__DOT__state = 3U;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->camera_interface__DOT__state))) {
                    if (((0U == (IData)(vlTOPp->camera_interface__DOT__col_count)) 
                         & (IData)(vlTOPp->href))) {
                        vlTOPp->__Vdly__camera_interface__DOT__row_count 
                            = (0x1ffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->camera_interface__DOT__row_count)));
                    }
                    vlTOPp->camera_interface__DOT__rst = 0U;
                    if (((IData)(vlTOPp->camera_interface__DOT__write_enable) 
                         & (IData)(vlTOPp->href))) {
                        vlTOPp->__Vdly__camera_interface__DOT__state = 2U;
                    }
                    if (((0x4ffU > (IData)(vlTOPp->camera_interface__DOT__col_count)) 
                         & (IData)(vlTOPp->href))) {
                        vlTOPp->__Vdly__camera_interface__DOT__col_count 
                            = (0x7ffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->camera_interface__DOT__col_count)));
                    }
                    if (((0x4ffU == (IData)(vlTOPp->camera_interface__DOT__col_count)) 
                         & (IData)(vlTOPp->href))) {
                        vlTOPp->__Vdly__camera_interface__DOT__col_count = 0U;
                    }
                } else {
                    if (vlTOPp->vsync) {
                        vlTOPp->__Vdly__camera_interface__DOT__col_count = 0U;
                        vlTOPp->__Vdly__camera_interface__DOT__row_count = 0U;
                        vlTOPp->__Vdly__camera_interface__DOT__state = 1U;
                        vlTOPp->camera_interface__DOT__rst = 1U;
                    }
                }
            }
        }
    }
    vlTOPp->camera_interface__DOT__state = vlTOPp->__Vdly__camera_interface__DOT__state;
    vlTOPp->camera_interface__DOT__col_count = vlTOPp->__Vdly__camera_interface__DOT__col_count;
    vlTOPp->camera_interface__DOT__row_count = vlTOPp->__Vdly__camera_interface__DOT__row_count;
    if ((9U == (IData)(vlTOPp->camera_interface__DOT__uut8__DOT__u1__DOT__counter))) {
        vlTOPp->camera_interface__DOT__uut8__DOT__Q2 
            = vlTOPp->camera_interface__DOT__uut8__DOT__Q1;
    }
    if ((9U == (IData)(vlTOPp->camera_interface__DOT__uut8__DOT__u1__DOT__counter))) {
        vlTOPp->camera_interface__DOT__uut8__DOT__Q1 
            = vlTOPp->camera_interface__DOT__uut8__DOT__Q0;
    }
    if ((9U == (IData)(vlTOPp->camera_interface__DOT__uut8__DOT__u1__DOT__counter))) {
        vlTOPp->camera_interface__DOT__uut8__DOT__Q0 
            = vlTOPp->shutter_raw;
    }
    vlTOPp->camera_interface__DOT__uut8__DOT__u1__DOT__counter 
        = vlTOPp->__Vdly__camera_interface__DOT__uut8__DOT__u1__DOT__counter;
}

VL_INLINE_OPT void Vcamera_interface::_combo__TOP__7(Vcamera_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_combo__TOP__7\n"); );
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->camera_interface__DOT__write_enable = (
                                                   ((IData)(vlTOPp->href) 
                                                    & (0xefU 
                                                       == (IData)(vlTOPp->camera_interface__DOT__row_count)))
                                                    ? 1U
                                                    : 0U);
}

void Vcamera_interface::_eval(Vcamera_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_eval\n"); );
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->pclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__pclk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    if (((~ (IData)(vlTOPp->pclk)) & (IData)(vlTOPp->__Vclklast__TOP__pclk))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__camera_interface__DOT__rst) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__camera_interface__DOT__rst))) 
         | ((IData)(vlTOPp->pclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__pclk))))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->pclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__pclk)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    vlTOPp->__Vm_traceActivity = (0x10U | vlTOPp->__Vm_traceActivity);
    // Final
    vlTOPp->__Vclklast__TOP__pclk = vlTOPp->pclk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__camera_interface__DOT__rst 
        = vlTOPp->__VinpClk__TOP__camera_interface__DOT__rst;
    vlTOPp->__VinpClk__TOP__camera_interface__DOT__rst 
        = vlTOPp->camera_interface__DOT__rst;
}

void Vcamera_interface::_eval_initial(Vcamera_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_eval_initial\n"); );
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__pclk = vlTOPp->pclk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__camera_interface__DOT__rst 
        = vlTOPp->__VinpClk__TOP__camera_interface__DOT__rst;
    vlTOPp->_initial__TOP__5(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

void Vcamera_interface::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::final\n"); );
    // Variables
    Vcamera_interface__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcamera_interface::_eval_settle(Vcamera_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_eval_settle\n"); );
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vcamera_interface::_change_request(Vcamera_interface__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_change_request\n"); );
    Vcamera_interface* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->camera_interface__DOT__rst ^ vlTOPp->__Vchglast__TOP__camera_interface__DOT__rst));
    VL_DEBUG_IF( if(__req && ((vlTOPp->camera_interface__DOT__rst ^ vlTOPp->__Vchglast__TOP__camera_interface__DOT__rst))) VL_DBG_MSGF("        CHANGE: camera_interface.sv:38: camera_interface.rst\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__camera_interface__DOT__rst 
        = vlTOPp->camera_interface__DOT__rst;
    return __req;
}

#ifdef VL_DEBUG
void Vcamera_interface::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((href & 0xfeU))) {
        Verilated::overWidthError("href");}
    if (VL_UNLIKELY((vsync & 0xfeU))) {
        Verilated::overWidthError("vsync");}
    if (VL_UNLIKELY((pclk & 0xfeU))) {
        Verilated::overWidthError("pclk");}
    if (VL_UNLIKELY((shutter_raw & 0xfeU))) {
        Verilated::overWidthError("shutter_raw");}
}
#endif  // VL_DEBUG

void Vcamera_interface::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcamera_interface::_ctor_var_reset\n"); );
    // Body
    reset = VL_RAND_RESET_I(1);
    href = VL_RAND_RESET_I(1);
    vsync = VL_RAND_RESET_I(1);
    pclk = VL_RAND_RESET_I(1);
    d = VL_RAND_RESET_I(8);
    shutter_raw = VL_RAND_RESET_I(1);
    fifo_enable = VL_RAND_RESET_I(1);
    wide_bit_out = VL_RAND_RESET_I(32);
    camera_interface__DOT__state = VL_RAND_RESET_I(2);
    camera_interface__DOT__col_count = VL_RAND_RESET_I(11);
    camera_interface__DOT__row_count = VL_RAND_RESET_I(9);
    camera_interface__DOT__clk_count = VL_RAND_RESET_I(3);
    camera_interface__DOT__q = VL_RAND_RESET_I(8);
    camera_interface__DOT__write_enable = VL_RAND_RESET_I(1);
    camera_interface__DOT__prev_vsync = VL_RAND_RESET_I(1);
    camera_interface__DOT__rst = VL_RAND_RESET_I(1);
    camera_interface__DOT____Vcellout__uut0__q = VL_RAND_RESET_I(1);
    camera_interface__DOT____Vcellout__uut1__q = VL_RAND_RESET_I(1);
    camera_interface__DOT____Vcellout__uut2__q = VL_RAND_RESET_I(1);
    camera_interface__DOT____Vcellout__uut3__q = VL_RAND_RESET_I(1);
    camera_interface__DOT____Vcellout__uut4__q = VL_RAND_RESET_I(1);
    camera_interface__DOT____Vcellout__uut5__q = VL_RAND_RESET_I(1);
    camera_interface__DOT____Vcellout__uut6__q = VL_RAND_RESET_I(1);
    camera_interface__DOT____Vcellout__uut7__q = VL_RAND_RESET_I(1);
    camera_interface__DOT__uut8__DOT__Q1 = VL_RAND_RESET_I(1);
    camera_interface__DOT__uut8__DOT__Q2 = VL_RAND_RESET_I(1);
    camera_interface__DOT__uut8__DOT__Q0 = VL_RAND_RESET_I(1);
    camera_interface__DOT__uut8__DOT__u1__DOT__counter = VL_RAND_RESET_I(4);
    __Vdly__camera_interface__DOT__state = VL_RAND_RESET_I(2);
    __Vdly__camera_interface__DOT__col_count = VL_RAND_RESET_I(11);
    __Vdly__camera_interface__DOT__row_count = VL_RAND_RESET_I(9);
    __Vdly__camera_interface__DOT__uut8__DOT__u1__DOT__counter = VL_RAND_RESET_I(4);
    __VinpClk__TOP__camera_interface__DOT__rst = VL_RAND_RESET_I(1);
    __Vchglast__TOP__camera_interface__DOT__rst = VL_RAND_RESET_I(1);
    __Vm_traceActivity = 0;
}
