// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMM2hdmi__Syms.h"


//======================

void VMM2hdmi::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VMM2hdmi* t=(VMM2hdmi*)userthis;
    VMM2hdmi__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VMM2hdmi::traceChgThis(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VMM2hdmi::traceChgThis__2(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+1,(vlTOPp->MM2hdmi__DOT__regNewData));
	vcdp->chgBus(c+2,(vlTOPp->MM2hdmi__DOT__regRow),5);
	vcdp->chgBit(c+3,(vlTOPp->MM2hdmi__DOT__regVSync));
	vcdp->chgBus(c+4,(vlTOPp->MM2hdmi__DOT__regData),16);
	vcdp->chgBus(c+5,(vlTOPp->MM2hdmi__DOT__regMuxRed0),8);
	vcdp->chgBus(c+6,(vlTOPp->MM2hdmi__DOT__regMuxRed1),8);
	vcdp->chgBus(c+7,(vlTOPp->MM2hdmi__DOT__regMuxRed2),8);
	vcdp->chgBus(c+8,(vlTOPp->MM2hdmi__DOT__regMuxRed3),8);
	vcdp->chgBus(c+9,(vlTOPp->MM2hdmi__DOT__regMuxRed4),8);
	vcdp->chgBus(c+10,(vlTOPp->MM2hdmi__DOT__regMuxRed5),8);
	vcdp->chgBus(c+11,(vlTOPp->MM2hdmi__DOT__regMuxRed6),8);
	vcdp->chgBus(c+12,(vlTOPp->MM2hdmi__DOT__regMuxRed7),8);
	vcdp->chgBus(c+13,(vlTOPp->MM2hdmi__DOT__regMuxRed8),8);
	vcdp->chgBus(c+14,(vlTOPp->MM2hdmi__DOT__regMuxRed9),8);
	vcdp->chgBus(c+15,(vlTOPp->MM2hdmi__DOT__regMuxRed10),8);
	vcdp->chgBus(c+16,(vlTOPp->MM2hdmi__DOT__regMuxRed11),8);
	vcdp->chgBus(c+17,(vlTOPp->MM2hdmi__DOT__regMuxRed12),8);
	vcdp->chgBus(c+18,(vlTOPp->MM2hdmi__DOT__regMuxRed13),8);
	vcdp->chgBus(c+19,(vlTOPp->MM2hdmi__DOT__regMuxRed14),8);
	vcdp->chgBus(c+20,(vlTOPp->MM2hdmi__DOT__regMuxRed15),8);
	vcdp->chgBus(c+21,(vlTOPp->MM2hdmi__DOT__outControlCounter),4);
    }
}

void VMM2hdmi::traceChgThis__3(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+22,(vlTOPp->clock));
	vcdp->chgBit(c+23,(vlTOPp->reset));
	vcdp->chgBus(c+24,(vlTOPp->io_data),16);
	vcdp->chgBit(c+25,(vlTOPp->io_newData));
	vcdp->chgBus(c+26,(vlTOPp->io_red),8);
	vcdp->chgBus(c+27,(vlTOPp->io_blue),8);
	vcdp->chgBus(c+28,(vlTOPp->io_green),8);
	vcdp->chgBit(c+29,(vlTOPp->io_vSync));
	vcdp->chgBit(c+30,(vlTOPp->io_hSync));
    }
}
