// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCAMERA_INTERFACE_H_
#define _VCAMERA_INTERFACE_H_  // guard

#include "verilated.h"

//==========

class Vcamera_interface__Syms;
class Vcamera_interface_VerilatedVcd;


//----------

VL_MODULE(Vcamera_interface) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(pclk,0,0);
    VL_IN8(shutter,0,0);
    VL_IN8(empty,0,0);
    VL_IN8(href,0,0);
    VL_IN8(vsync,0,0);
    VL_IN8(d,7,0);
    VL_OUT8(fifo_enable,0,0);
    VL_OUT8(clk,0,0);
    VL_OUT(wide_bit_out,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*1:0*/ camera_interface__DOT__state;
    CData/*2:0*/ camera_interface__DOT__clk_count;
    CData/*7:0*/ camera_interface__DOT__q;
    CData/*0:0*/ camera_interface__DOT__write_enable;
    CData/*0:0*/ camera_interface__DOT__prev_vsync;
    CData/*0:0*/ camera_interface__DOT__ready;
    SData/*10:0*/ camera_interface__DOT__col_count;
    SData/*8:0*/ camera_interface__DOT__row_count;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ camera_interface__DOT____Vcellout__uut0__q;
    CData/*0:0*/ camera_interface__DOT____Vcellout__uut1__q;
    CData/*0:0*/ camera_interface__DOT____Vcellout__uut2__q;
    CData/*0:0*/ camera_interface__DOT____Vcellout__uut3__q;
    CData/*0:0*/ camera_interface__DOT____Vcellout__uut4__q;
    CData/*0:0*/ camera_interface__DOT____Vcellout__uut5__q;
    CData/*0:0*/ camera_interface__DOT____Vcellout__uut6__q;
    CData/*0:0*/ camera_interface__DOT____Vcellout__uut7__q;
    CData/*0:0*/ __Vclklast__TOP__pclk;
    CData/*0:0*/ __Vclklast__TOP__empty;
    CData/*0:0*/ __Vclklast__TOP__shutter;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcamera_interface__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcamera_interface);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vcamera_interface(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcamera_interface();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcamera_interface__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcamera_interface__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcamera_interface__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vcamera_interface__Syms* __restrict vlSymsp);
    static void _combo__TOP__7(Vcamera_interface__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vcamera_interface__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vcamera_interface__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vcamera_interface__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Vcamera_interface__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vcamera_interface__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vcamera_interface__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vcamera_interface__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vcamera_interface__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__7(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vcamera_interface__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
