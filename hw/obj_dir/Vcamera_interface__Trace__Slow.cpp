// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcamera_interface__Syms.h"


//======================

void Vcamera_interface::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vcamera_interface::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcamera_interface__Syms* __restrict vlSymsp = static_cast<Vcamera_interface__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vcamera_interface::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vcamera_interface::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vcamera_interface__Syms* __restrict vlSymsp = static_cast<Vcamera_interface__Syms*>(userp);
    Vcamera_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vcamera_interface::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vcamera_interface__Syms* __restrict vlSymsp = static_cast<Vcamera_interface__Syms*>(userp);
    Vcamera_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"reset", false,-1);
        tracep->declBus(c+3,"d", false,-1, 7,0);
        tracep->declBit(c+4,"href", false,-1);
        tracep->declBit(c+5,"vsync", false,-1);
        tracep->declBit(c+6,"hsync", false,-1);
        tracep->declBus(c+7,"q", false,-1, 7,0);
        tracep->declBit(c+1,"camera_interface clk", false,-1);
        tracep->declBit(c+2,"camera_interface reset", false,-1);
        tracep->declBus(c+3,"camera_interface d", false,-1, 7,0);
        tracep->declBit(c+4,"camera_interface href", false,-1);
        tracep->declBit(c+5,"camera_interface vsync", false,-1);
        tracep->declBit(c+6,"camera_interface hsync", false,-1);
        tracep->declBus(c+7,"camera_interface q", false,-1, 7,0);
    }
}

void Vcamera_interface::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vcamera_interface::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vcamera_interface__Syms* __restrict vlSymsp = static_cast<Vcamera_interface__Syms*>(userp);
    Vcamera_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vcamera_interface::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vcamera_interface__Syms* __restrict vlSymsp = static_cast<Vcamera_interface__Syms*>(userp);
    Vcamera_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk));
        tracep->fullBit(oldp+2,(vlTOPp->reset));
        tracep->fullCData(oldp+3,(vlTOPp->d),8);
        tracep->fullBit(oldp+4,(vlTOPp->href));
        tracep->fullBit(oldp+5,(vlTOPp->vsync));
        tracep->fullBit(oldp+6,(vlTOPp->hsync));
        tracep->fullCData(oldp+7,(vlTOPp->q),8);
    }
}
