// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMM2hdmi_H_
#define _VMM2hdmi_H_

#include "verilated.h"

class VMM2hdmi__Syms;
class VerilatedVcd;

//----------

VL_MODULE(VMM2hdmi) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_newData,0,0);
    VL_OUT8(io_red,7,0);
    VL_OUT8(io_blue,7,0);
    VL_OUT8(io_green,7,0);
    VL_OUT8(io_vSync,0,0);
    VL_OUT8(io_hSync,0,0);
    VL_IN16(io_data,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(MM2hdmi__DOT__regNewData,0,0);
    VL_SIG8(MM2hdmi__DOT__regHSync,0,0);
    VL_SIG8(MM2hdmi__DOT___T_1,0,0);
    VL_SIG8(MM2hdmi__DOT__regRow,4,0);
    VL_SIG8(MM2hdmi__DOT___T_4,4,0);
    VL_SIG8(MM2hdmi__DOT__regVSync,0,0);
    VL_SIG8(MM2hdmi__DOT___GEN_1,0,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed0,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed1,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed2,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed3,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed4,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed5,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed6,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed7,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed8,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed9,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed10,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed11,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed12,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed13,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed14,7,0);
    VL_SIG8(MM2hdmi__DOT__regMuxRed15,7,0);
    VL_SIG8(MM2hdmi__DOT__outControlCounter,3,0);
    VL_SIG8(MM2hdmi__DOT___T_60,0,0);
    VL_SIG8(MM2hdmi__DOT___T_62,3,0);
    VL_SIG8(MM2hdmi__DOT___GEN_15,7,0);
    VL_SIG16(MM2hdmi__DOT__regData,15,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VMM2hdmi__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VMM2hdmi);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VMM2hdmi(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VMM2hdmi();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VMM2hdmi__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VMM2hdmi__Syms* symsp, bool first);
  private:
    static QData _change_request(VMM2hdmi__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(VMM2hdmi__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VMM2hdmi__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(VMM2hdmi__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VMM2hdmi__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(VMM2hdmi__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VMM2hdmi__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VMM2hdmi__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
