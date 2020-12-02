// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMM2hdmi__Syms.h"


//======================

void VMM2hdmi::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VMM2hdmi::traceInit, &VMM2hdmi::traceFull, &VMM2hdmi::traceChg, this);
}
void VMM2hdmi::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VMM2hdmi* t=(VMM2hdmi*)userthis;
    VMM2hdmi__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
	VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VMM2hdmi::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VMM2hdmi* t=(VMM2hdmi*)userthis;
    VMM2hdmi__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VMM2hdmi::traceInitThis(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VMM2hdmi::traceFullThis(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VMM2hdmi::traceInitThis__1(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit(c+23,"clock",-1);
	vcdp->declBit(c+24,"reset",-1);
	vcdp->declBus(c+25,"io_data",-1,15,0);
	vcdp->declBit(c+26,"io_newData",-1);
	vcdp->declBus(c+27,"io_red",-1,7,0);
	vcdp->declBus(c+28,"io_blue",-1,7,0);
	vcdp->declBus(c+29,"io_green",-1,7,0);
	vcdp->declBit(c+30,"io_vSync",-1);
	vcdp->declBit(c+31,"io_hSync",-1);
	vcdp->declBit(c+23,"MM2hdmi clock",-1);
	vcdp->declBit(c+24,"MM2hdmi reset",-1);
	vcdp->declBus(c+25,"MM2hdmi io_data",-1,15,0);
	vcdp->declBit(c+26,"MM2hdmi io_newData",-1);
	vcdp->declBus(c+27,"MM2hdmi io_red",-1,7,0);
	vcdp->declBus(c+28,"MM2hdmi io_blue",-1,7,0);
	vcdp->declBus(c+29,"MM2hdmi io_green",-1,7,0);
	vcdp->declBit(c+30,"MM2hdmi io_vSync",-1);
	vcdp->declBit(c+31,"MM2hdmi io_hSync",-1);
	vcdp->declBit(c+1,"MM2hdmi regNewData",-1);
	vcdp->declBit(c+2,"MM2hdmi regHSync",-1);
	// Tracing: MM2hdmi _T_1 // Ignored: Inlined leading underscore at MM2hdmi.v:38
	vcdp->declBus(c+3,"MM2hdmi regRow",-1,4,0);
	// Tracing: MM2hdmi _T_4 // Ignored: Inlined leading underscore at MM2hdmi.v:40
	vcdp->declBit(c+4,"MM2hdmi regVSync",-1);
	// Tracing: MM2hdmi _T_5 // Ignored: Inlined leading underscore at MM2hdmi.v:42
	// Tracing: MM2hdmi _T_7 // Ignored: Inlined leading underscore at MM2hdmi.v:43
	vcdp->declBus(c+5,"MM2hdmi regData",-1,15,0);
	// Tracing: MM2hdmi _T_9 // Ignored: Inlined leading underscore at MM2hdmi.v:45
	vcdp->declBus(c+6,"MM2hdmi regMuxRed0",-1,7,0);
	// Tracing: MM2hdmi _T_12 // Ignored: Inlined leading underscore at MM2hdmi.v:47
	vcdp->declBus(c+7,"MM2hdmi regMuxRed1",-1,7,0);
	// Tracing: MM2hdmi _T_15 // Ignored: Inlined leading underscore at MM2hdmi.v:49
	vcdp->declBus(c+8,"MM2hdmi regMuxRed2",-1,7,0);
	// Tracing: MM2hdmi _T_18 // Ignored: Inlined leading underscore at MM2hdmi.v:51
	vcdp->declBus(c+9,"MM2hdmi regMuxRed3",-1,7,0);
	// Tracing: MM2hdmi _T_21 // Ignored: Inlined leading underscore at MM2hdmi.v:53
	vcdp->declBus(c+10,"MM2hdmi regMuxRed4",-1,7,0);
	// Tracing: MM2hdmi _T_24 // Ignored: Inlined leading underscore at MM2hdmi.v:55
	vcdp->declBus(c+11,"MM2hdmi regMuxRed5",-1,7,0);
	// Tracing: MM2hdmi _T_27 // Ignored: Inlined leading underscore at MM2hdmi.v:57
	vcdp->declBus(c+12,"MM2hdmi regMuxRed6",-1,7,0);
	// Tracing: MM2hdmi _T_30 // Ignored: Inlined leading underscore at MM2hdmi.v:59
	vcdp->declBus(c+13,"MM2hdmi regMuxRed7",-1,7,0);
	// Tracing: MM2hdmi _T_33 // Ignored: Inlined leading underscore at MM2hdmi.v:61
	vcdp->declBus(c+14,"MM2hdmi regMuxRed8",-1,7,0);
	// Tracing: MM2hdmi _T_36 // Ignored: Inlined leading underscore at MM2hdmi.v:63
	vcdp->declBus(c+15,"MM2hdmi regMuxRed9",-1,7,0);
	// Tracing: MM2hdmi _T_39 // Ignored: Inlined leading underscore at MM2hdmi.v:65
	vcdp->declBus(c+16,"MM2hdmi regMuxRed10",-1,7,0);
	// Tracing: MM2hdmi _T_42 // Ignored: Inlined leading underscore at MM2hdmi.v:67
	vcdp->declBus(c+17,"MM2hdmi regMuxRed11",-1,7,0);
	// Tracing: MM2hdmi _T_45 // Ignored: Inlined leading underscore at MM2hdmi.v:69
	vcdp->declBus(c+18,"MM2hdmi regMuxRed12",-1,7,0);
	// Tracing: MM2hdmi _T_48 // Ignored: Inlined leading underscore at MM2hdmi.v:71
	vcdp->declBus(c+19,"MM2hdmi regMuxRed13",-1,7,0);
	// Tracing: MM2hdmi _T_51 // Ignored: Inlined leading underscore at MM2hdmi.v:73
	vcdp->declBus(c+20,"MM2hdmi regMuxRed14",-1,7,0);
	// Tracing: MM2hdmi _T_54 // Ignored: Inlined leading underscore at MM2hdmi.v:75
	vcdp->declBus(c+21,"MM2hdmi regMuxRed15",-1,7,0);
	vcdp->declBus(c+22,"MM2hdmi outControlCounter",-1,3,0);
	// Tracing: MM2hdmi _T_56 // Ignored: Inlined leading underscore at MM2hdmi.v:78
	// Tracing: MM2hdmi _T_58 // Ignored: Inlined leading underscore at MM2hdmi.v:79
	// Tracing: MM2hdmi _T_60 // Ignored: Inlined leading underscore at MM2hdmi.v:80
	// Tracing: MM2hdmi _T_62 // Ignored: Inlined leading underscore at MM2hdmi.v:81
	// Tracing: MM2hdmi _T_63 // Ignored: Inlined leading underscore at MM2hdmi.v:82
	// Tracing: MM2hdmi _T_64 // Ignored: Inlined leading underscore at MM2hdmi.v:83
	// Tracing: MM2hdmi _T_65 // Ignored: Inlined leading underscore at MM2hdmi.v:84
	// Tracing: MM2hdmi _T_66 // Ignored: Inlined leading underscore at MM2hdmi.v:85
	// Tracing: MM2hdmi _T_67 // Ignored: Inlined leading underscore at MM2hdmi.v:86
	// Tracing: MM2hdmi _T_68 // Ignored: Inlined leading underscore at MM2hdmi.v:87
	// Tracing: MM2hdmi _T_69 // Ignored: Inlined leading underscore at MM2hdmi.v:88
	// Tracing: MM2hdmi _T_70 // Ignored: Inlined leading underscore at MM2hdmi.v:89
	// Tracing: MM2hdmi _T_71 // Ignored: Inlined leading underscore at MM2hdmi.v:90
	// Tracing: MM2hdmi _T_72 // Ignored: Inlined leading underscore at MM2hdmi.v:91
	// Tracing: MM2hdmi _T_73 // Ignored: Inlined leading underscore at MM2hdmi.v:92
	// Tracing: MM2hdmi _T_74 // Ignored: Inlined leading underscore at MM2hdmi.v:93
	// Tracing: MM2hdmi _T_75 // Ignored: Inlined leading underscore at MM2hdmi.v:94
	// Tracing: MM2hdmi _T_76 // Ignored: Inlined leading underscore at MM2hdmi.v:95
	// Tracing: MM2hdmi _GEN_2 // Ignored: Inlined leading underscore at MM2hdmi.v:96
	// Tracing: MM2hdmi _GEN_3 // Ignored: Inlined leading underscore at MM2hdmi.v:97
	// Tracing: MM2hdmi _GEN_4 // Ignored: Inlined leading underscore at MM2hdmi.v:98
	// Tracing: MM2hdmi _GEN_5 // Ignored: Inlined leading underscore at MM2hdmi.v:99
	// Tracing: MM2hdmi _GEN_6 // Ignored: Inlined leading underscore at MM2hdmi.v:100
	// Tracing: MM2hdmi _GEN_7 // Ignored: Inlined leading underscore at MM2hdmi.v:101
	// Tracing: MM2hdmi _GEN_8 // Ignored: Inlined leading underscore at MM2hdmi.v:102
	// Tracing: MM2hdmi _GEN_9 // Ignored: Inlined leading underscore at MM2hdmi.v:103
	// Tracing: MM2hdmi _GEN_10 // Ignored: Inlined leading underscore at MM2hdmi.v:104
	// Tracing: MM2hdmi _GEN_11 // Ignored: Inlined leading underscore at MM2hdmi.v:105
	// Tracing: MM2hdmi _GEN_12 // Ignored: Inlined leading underscore at MM2hdmi.v:106
	// Tracing: MM2hdmi _GEN_13 // Ignored: Inlined leading underscore at MM2hdmi.v:107
	// Tracing: MM2hdmi _GEN_14 // Ignored: Inlined leading underscore at MM2hdmi.v:108
	// Tracing: MM2hdmi _GEN_15 // Ignored: Inlined leading underscore at MM2hdmi.v:109
    }
}

void VMM2hdmi::traceFullThis__1(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBit(c+1,(vlTOPp->MM2hdmi__DOT__regNewData));
	vcdp->fullBit(c+2,(vlTOPp->MM2hdmi__DOT__regHSync));
	vcdp->fullBus(c+3,(vlTOPp->MM2hdmi__DOT__regRow),5);
	vcdp->fullBit(c+4,(vlTOPp->MM2hdmi__DOT__regVSync));
	vcdp->fullBus(c+5,(vlTOPp->MM2hdmi__DOT__regData),16);
	vcdp->fullBus(c+6,(vlTOPp->MM2hdmi__DOT__regMuxRed0),8);
	vcdp->fullBus(c+7,(vlTOPp->MM2hdmi__DOT__regMuxRed1),8);
	vcdp->fullBus(c+8,(vlTOPp->MM2hdmi__DOT__regMuxRed2),8);
	vcdp->fullBus(c+9,(vlTOPp->MM2hdmi__DOT__regMuxRed3),8);
	vcdp->fullBus(c+10,(vlTOPp->MM2hdmi__DOT__regMuxRed4),8);
	vcdp->fullBus(c+11,(vlTOPp->MM2hdmi__DOT__regMuxRed5),8);
	vcdp->fullBus(c+12,(vlTOPp->MM2hdmi__DOT__regMuxRed6),8);
	vcdp->fullBus(c+13,(vlTOPp->MM2hdmi__DOT__regMuxRed7),8);
	vcdp->fullBus(c+14,(vlTOPp->MM2hdmi__DOT__regMuxRed8),8);
	vcdp->fullBus(c+15,(vlTOPp->MM2hdmi__DOT__regMuxRed9),8);
	vcdp->fullBus(c+16,(vlTOPp->MM2hdmi__DOT__regMuxRed10),8);
	vcdp->fullBus(c+17,(vlTOPp->MM2hdmi__DOT__regMuxRed11),8);
	vcdp->fullBus(c+18,(vlTOPp->MM2hdmi__DOT__regMuxRed12),8);
	vcdp->fullBus(c+19,(vlTOPp->MM2hdmi__DOT__regMuxRed13),8);
	vcdp->fullBus(c+20,(vlTOPp->MM2hdmi__DOT__regMuxRed14),8);
	vcdp->fullBus(c+21,(vlTOPp->MM2hdmi__DOT__regMuxRed15),8);
	vcdp->fullBus(c+22,(vlTOPp->MM2hdmi__DOT__outControlCounter),4);
	vcdp->fullBit(c+23,(vlTOPp->clock));
	vcdp->fullBit(c+24,(vlTOPp->reset));
	vcdp->fullBus(c+25,(vlTOPp->io_data),16);
	vcdp->fullBit(c+26,(vlTOPp->io_newData));
	vcdp->fullBus(c+27,(vlTOPp->io_red),8);
	vcdp->fullBus(c+28,(vlTOPp->io_blue),8);
	vcdp->fullBus(c+29,(vlTOPp->io_green),8);
	vcdp->fullBit(c+30,(vlTOPp->io_vSync));
	vcdp->fullBit(c+31,(vlTOPp->io_hSync));
    }
}
