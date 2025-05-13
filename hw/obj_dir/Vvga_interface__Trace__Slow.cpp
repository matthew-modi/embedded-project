// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vvga_interface__Syms.h"


//======================

void Vvga_interface::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vvga_interface::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vvga_interface__Syms* __restrict vlSymsp = static_cast<Vvga_interface__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vvga_interface::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vvga_interface::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vvga_interface__Syms* __restrict vlSymsp = static_cast<Vvga_interface__Syms*>(userp);
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vvga_interface::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vvga_interface__Syms* __restrict vlSymsp = static_cast<Vvga_interface__Syms*>(userp);
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"pclk", false,-1);
        tracep->declBit(c+2,"reset", false,-1);
        tracep->declBit(c+3,"cam_href", false,-1);
        tracep->declBit(c+4,"cam_vsync", false,-1);
        tracep->declBus(c+5,"cam_data", false,-1, 7,0);
        tracep->declBit(c+6,"VGA_CLK", false,-1);
        tracep->declBit(c+7,"VGA_HS", false,-1);
        tracep->declBit(c+8,"VGA_VS", false,-1);
        tracep->declBit(c+9,"VGA_BLANK_n", false,-1);
        tracep->declBit(c+10,"VGA_SYNC_n", false,-1);
        tracep->declBus(c+11,"VGA_R", false,-1, 7,0);
        tracep->declBus(c+12,"VGA_G", false,-1, 7,0);
        tracep->declBus(c+13,"VGA_B", false,-1, 7,0);
        tracep->declBit(c+1,"vga_interface pclk", false,-1);
        tracep->declBit(c+2,"vga_interface reset", false,-1);
        tracep->declBit(c+3,"vga_interface cam_href", false,-1);
        tracep->declBit(c+4,"vga_interface cam_vsync", false,-1);
        tracep->declBus(c+5,"vga_interface cam_data", false,-1, 7,0);
        tracep->declBit(c+6,"vga_interface VGA_CLK", false,-1);
        tracep->declBit(c+7,"vga_interface VGA_HS", false,-1);
        tracep->declBit(c+8,"vga_interface VGA_VS", false,-1);
        tracep->declBit(c+9,"vga_interface VGA_BLANK_n", false,-1);
        tracep->declBit(c+10,"vga_interface VGA_SYNC_n", false,-1);
        tracep->declBus(c+11,"vga_interface VGA_R", false,-1, 7,0);
        tracep->declBus(c+12,"vga_interface VGA_G", false,-1, 7,0);
        tracep->declBus(c+13,"vga_interface VGA_B", false,-1, 7,0);
        tracep->declBit(c+14,"vga_interface byte_flag", false,-1);
        tracep->declBus(c+15,"vga_interface pix16", false,-1, 15,0);
    }
}

void Vvga_interface::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vvga_interface::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vvga_interface__Syms* __restrict vlSymsp = static_cast<Vvga_interface__Syms*>(userp);
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vvga_interface::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vvga_interface__Syms* __restrict vlSymsp = static_cast<Vvga_interface__Syms*>(userp);
    Vvga_interface* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->pclk));
        tracep->fullBit(oldp+2,(vlTOPp->reset));
        tracep->fullBit(oldp+3,(vlTOPp->cam_href));
        tracep->fullBit(oldp+4,(vlTOPp->cam_vsync));
        tracep->fullCData(oldp+5,(vlTOPp->cam_data),8);
        tracep->fullBit(oldp+6,(vlTOPp->VGA_CLK));
        tracep->fullBit(oldp+7,(vlTOPp->VGA_HS));
        tracep->fullBit(oldp+8,(vlTOPp->VGA_VS));
        tracep->fullBit(oldp+9,(vlTOPp->VGA_BLANK_n));
        tracep->fullBit(oldp+10,(vlTOPp->VGA_SYNC_n));
        tracep->fullCData(oldp+11,(vlTOPp->VGA_R),8);
        tracep->fullCData(oldp+12,(vlTOPp->VGA_G),8);
        tracep->fullCData(oldp+13,(vlTOPp->VGA_B),8);
        tracep->fullBit(oldp+14,(vlTOPp->vga_interface__DOT__byte_flag));
        tracep->fullSData(oldp+15,(vlTOPp->vga_interface__DOT__pix16),16);
    }
}
