// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMM2hdmi.h for the primary calling header

#include "VMM2hdmi.h"
#include "VMM2hdmi__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMM2hdmi) {
    VMM2hdmi__Syms* __restrict vlSymsp = __VlSymsp = new VMM2hdmi__Syms(this, name());
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VMM2hdmi::__Vconfigure(VMM2hdmi__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMM2hdmi::~VMM2hdmi() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VMM2hdmi::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMM2hdmi::eval\n"); );
    VMM2hdmi__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void VMM2hdmi::_eval_initial_loop(VMM2hdmi__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
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
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VMM2hdmi::_sequent__TOP__1(VMM2hdmi__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMM2hdmi::_sequent__TOP__1\n"); );
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regNewData = vlTOPp->io_newData;
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regVSync = ((~ (IData)(vlTOPp->reset)) 
				      & (IData)(vlTOPp->MM2hdmi__DOT___GEN_1));
    // ALWAYS at MM2hdmi.v:194
    if (vlTOPp->reset) {
	vlTOPp->MM2hdmi__DOT__regRow = 0U;
    } else {
	if (vlTOPp->io_newData) {
	    vlTOPp->MM2hdmi__DOT__regRow = vlTOPp->MM2hdmi__DOT___T_2;
	}
    }
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed14 = ((0x4000U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					  ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed13 = ((0x2000U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					  ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed12 = ((0x1000U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					  ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed1 = ((2U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					 ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed0 = ((1U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					 ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed15 = ((0x8000U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					  ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed5 = ((0x20U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					 ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed2 = ((4U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					 ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed3 = ((8U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					 ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed4 = ((0x10U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					 ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed6 = ((0x40U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					 ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed7 = ((0x80U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					 ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed8 = ((0x100U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					 ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed9 = ((0x200U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					 ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed10 = ((0x400U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					  ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regMuxRed11 = ((0x800U & (IData)(vlTOPp->MM2hdmi__DOT__regData))
					  ? 0xffU : 0U);
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__outControlCounter = ((IData)(vlTOPp->reset)
					        ? 0U
					        : ((IData)(vlTOPp->MM2hdmi__DOT___T_58)
						    ? 0U
						    : (IData)(vlTOPp->MM2hdmi__DOT___T_60)));
    vlTOPp->io_hSync = vlTOPp->MM2hdmi__DOT__regNewData;
    vlTOPp->io_vSync = vlTOPp->MM2hdmi__DOT__regVSync;
    vlTOPp->MM2hdmi__DOT___T_2 = (0x1fU & ((IData)(1U) 
					   + (IData)(vlTOPp->MM2hdmi__DOT__regRow)));
    // ALWAYS at MM2hdmi.v:194
    vlTOPp->MM2hdmi__DOT__regData = vlTOPp->io_data;
    vlTOPp->MM2hdmi__DOT___T_60 = (0xfU & ((IData)(1U) 
					   + (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter)));
    vlTOPp->MM2hdmi__DOT___T_58 = ((0xfU == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter)) 
				   | (IData)(vlTOPp->MM2hdmi__DOT__regNewData));
    vlTOPp->io_red = ((0U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
		       ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed0)
		       : ((1U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
			   ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed1)
			   : ((2U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
			       ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed2)
			       : ((3U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
				   ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed3)
				   : ((4U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
				       ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed4)
				       : ((5U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
					   ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed5)
					   : ((6U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
					       ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed6)
					       : ((7U 
						   == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
						   ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed7)
						   : 
						  ((8U 
						    == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
						    ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed8)
						    : 
						   ((9U 
						     == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
						     ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed9)
						     : 
						    ((0xaU 
						      == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
						      ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed10)
						      : 
						     ((0xbU 
						       == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
						       ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed11)
						       : 
						      ((0xcU 
							== (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
						        ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed12)
						        : 
						       ((0xdU 
							 == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
							 ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed13)
							 : 
							((0xeU 
							  == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
							  ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed14)
							  : (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed15))))))))))))))));
}

void VMM2hdmi::_settle__TOP__2(VMM2hdmi__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMM2hdmi::_settle__TOP__2\n"); );
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->MM2hdmi__DOT___T_2 = (0x1fU & ((IData)(1U) 
					   + (IData)(vlTOPp->MM2hdmi__DOT__regRow)));
    vlTOPp->MM2hdmi__DOT___T_60 = (0xfU & ((IData)(1U) 
					   + (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter)));
    vlTOPp->io_vSync = vlTOPp->MM2hdmi__DOT__regVSync;
    vlTOPp->io_hSync = vlTOPp->MM2hdmi__DOT__regNewData;
    vlTOPp->MM2hdmi__DOT___T_58 = ((0xfU == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter)) 
				   | (IData)(vlTOPp->MM2hdmi__DOT__regNewData));
    vlTOPp->MM2hdmi__DOT___GEN_1 = (((0x1fU == (IData)(vlTOPp->MM2hdmi__DOT__regRow)) 
				     & (IData)(vlTOPp->io_newData)) 
				    & ((IData)(1U) 
				       + (IData)(vlTOPp->MM2hdmi__DOT__regVSync)));
    vlTOPp->io_red = ((0U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
		       ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed0)
		       : ((1U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
			   ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed1)
			   : ((2U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
			       ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed2)
			       : ((3U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
				   ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed3)
				   : ((4U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
				       ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed4)
				       : ((5U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
					   ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed5)
					   : ((6U == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
					       ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed6)
					       : ((7U 
						   == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
						   ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed7)
						   : 
						  ((8U 
						    == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
						    ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed8)
						    : 
						   ((9U 
						     == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
						     ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed9)
						     : 
						    ((0xaU 
						      == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
						      ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed10)
						      : 
						     ((0xbU 
						       == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
						       ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed11)
						       : 
						      ((0xcU 
							== (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
						        ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed12)
						        : 
						       ((0xdU 
							 == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
							 ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed13)
							 : 
							((0xeU 
							  == (IData)(vlTOPp->MM2hdmi__DOT__outControlCounter))
							  ? (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed14)
							  : (IData)(vlTOPp->MM2hdmi__DOT__regMuxRed15))))))))))))))));
}

VL_INLINE_OPT void VMM2hdmi::_combo__TOP__3(VMM2hdmi__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMM2hdmi::_combo__TOP__3\n"); );
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->MM2hdmi__DOT___GEN_1 = (((0x1fU == (IData)(vlTOPp->MM2hdmi__DOT__regRow)) 
				     & (IData)(vlTOPp->io_newData)) 
				    & ((IData)(1U) 
				       + (IData)(vlTOPp->MM2hdmi__DOT__regVSync)));
}

void VMM2hdmi::_eval(VMM2hdmi__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMM2hdmi::_eval\n"); );
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VMM2hdmi::_eval_initial(VMM2hdmi__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMM2hdmi::_eval_initial\n"); );
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VMM2hdmi::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMM2hdmi::final\n"); );
    // Variables
    VMM2hdmi__Syms* __restrict vlSymsp = this->__VlSymsp;
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMM2hdmi::_eval_settle(VMM2hdmi__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMM2hdmi::_eval_settle\n"); );
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VMM2hdmi::_change_request(VMM2hdmi__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMM2hdmi::_change_request\n"); );
    VMM2hdmi* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VMM2hdmi::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMM2hdmi::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
	Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_newData & 0xfeU))) {
	Verilated::overWidthError("io_newData");}
}
#endif // VL_DEBUG

void VMM2hdmi::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMM2hdmi::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_data = VL_RAND_RESET_I(16);
    io_newData = VL_RAND_RESET_I(1);
    io_red = VL_RAND_RESET_I(8);
    io_vSync = VL_RAND_RESET_I(1);
    io_hSync = VL_RAND_RESET_I(1);
    MM2hdmi__DOT__regNewData = VL_RAND_RESET_I(1);
    MM2hdmi__DOT__regRow = VL_RAND_RESET_I(5);
    MM2hdmi__DOT___T_2 = VL_RAND_RESET_I(5);
    MM2hdmi__DOT__regVSync = VL_RAND_RESET_I(1);
    MM2hdmi__DOT___GEN_1 = VL_RAND_RESET_I(1);
    MM2hdmi__DOT__regData = VL_RAND_RESET_I(16);
    MM2hdmi__DOT__regMuxRed0 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed1 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed2 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed3 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed4 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed5 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed6 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed7 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed8 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed9 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed10 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed11 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed12 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed13 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed14 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__regMuxRed15 = VL_RAND_RESET_I(8);
    MM2hdmi__DOT__outControlCounter = VL_RAND_RESET_I(4);
    MM2hdmi__DOT___T_58 = VL_RAND_RESET_I(1);
    MM2hdmi__DOT___T_60 = VL_RAND_RESET_I(4);
}
