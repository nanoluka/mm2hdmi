module MM2hdmi(
  input         clock,
  input         reset,
  input  [15:0] io_data,
  input         io_newData,
  output [7:0]  io_red,
  output        io_vSync,
  output        io_hSync
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
`endif // RANDOMIZE_REG_INIT
  reg  regNewData; // @[mm2hdmi.scala 17:27]
  reg [4:0] regRow; // @[mm2hdmi.scala 19:23]
  wire [4:0] _T_2 = regRow + 5'h1; // @[mm2hdmi.scala 21:22]
  reg  regVSync; // @[mm2hdmi.scala 24:25]
  wire  _T_3 = regRow == 5'h1f; // @[mm2hdmi.scala 25:15]
  wire  _T_5 = _T_3 & io_newData; // @[mm2hdmi.scala 25:24]
  wire  _T_7 = regVSync + 1'h1; // @[mm2hdmi.scala 26:26]
  wire  _GEN_1 = _T_5 & _T_7; // @[mm2hdmi.scala 25:47]
  reg [15:0] regData; // @[mm2hdmi.scala 32:24]
  wire  _T_9 = ~regData[0]; // @[mm2hdmi.scala 34:43]
  reg [7:0] regMuxRed0; // @[mm2hdmi.scala 34:27]
  wire  _T_12 = ~regData[1]; // @[mm2hdmi.scala 35:43]
  reg [7:0] regMuxRed1; // @[mm2hdmi.scala 35:27]
  wire  _T_15 = ~regData[2]; // @[mm2hdmi.scala 36:43]
  reg [7:0] regMuxRed2; // @[mm2hdmi.scala 36:27]
  wire  _T_18 = ~regData[3]; // @[mm2hdmi.scala 37:43]
  reg [7:0] regMuxRed3; // @[mm2hdmi.scala 37:27]
  wire  _T_21 = ~regData[4]; // @[mm2hdmi.scala 38:43]
  reg [7:0] regMuxRed4; // @[mm2hdmi.scala 38:27]
  wire  _T_24 = ~regData[5]; // @[mm2hdmi.scala 39:43]
  reg [7:0] regMuxRed5; // @[mm2hdmi.scala 39:27]
  wire  _T_27 = ~regData[6]; // @[mm2hdmi.scala 40:43]
  reg [7:0] regMuxRed6; // @[mm2hdmi.scala 40:27]
  wire  _T_30 = ~regData[7]; // @[mm2hdmi.scala 41:43]
  reg [7:0] regMuxRed7; // @[mm2hdmi.scala 41:27]
  wire  _T_33 = ~regData[8]; // @[mm2hdmi.scala 42:43]
  reg [7:0] regMuxRed8; // @[mm2hdmi.scala 42:27]
  wire  _T_36 = ~regData[9]; // @[mm2hdmi.scala 43:43]
  reg [7:0] regMuxRed9; // @[mm2hdmi.scala 43:27]
  wire  _T_39 = ~regData[10]; // @[mm2hdmi.scala 44:45]
  reg [7:0] regMuxRed10; // @[mm2hdmi.scala 44:28]
  wire  _T_42 = ~regData[11]; // @[mm2hdmi.scala 45:45]
  reg [7:0] regMuxRed11; // @[mm2hdmi.scala 45:28]
  wire  _T_45 = ~regData[12]; // @[mm2hdmi.scala 46:45]
  reg [7:0] regMuxRed12; // @[mm2hdmi.scala 46:28]
  wire  _T_48 = ~regData[13]; // @[mm2hdmi.scala 47:45]
  reg [7:0] regMuxRed13; // @[mm2hdmi.scala 47:28]
  wire  _T_51 = ~regData[14]; // @[mm2hdmi.scala 48:45]
  reg [7:0] regMuxRed14; // @[mm2hdmi.scala 48:28]
  wire  _T_54 = ~regData[15]; // @[mm2hdmi.scala 49:45]
  reg [7:0] regMuxRed15; // @[mm2hdmi.scala 49:28]
  reg [3:0] outControlCounter; // @[mm2hdmi.scala 51:34]
  wire  _T_56 = outControlCounter == 4'hf; // @[mm2hdmi.scala 52:46]
  wire  _T_58 = _T_56 | regNewData; // @[mm2hdmi.scala 52:55]
  wire [3:0] _T_60 = outControlCounter + 4'h1; // @[mm2hdmi.scala 52:101]
  wire  _T_62 = outControlCounter == 4'h0; // @[mm2hdmi.scala 54:27]
  wire  _T_63 = outControlCounter == 4'h1; // @[mm2hdmi.scala 57:32]
  wire  _T_64 = outControlCounter == 4'h2; // @[mm2hdmi.scala 60:32]
  wire  _T_65 = outControlCounter == 4'h3; // @[mm2hdmi.scala 63:32]
  wire  _T_66 = outControlCounter == 4'h4; // @[mm2hdmi.scala 66:32]
  wire  _T_67 = outControlCounter == 4'h5; // @[mm2hdmi.scala 69:32]
  wire  _T_68 = outControlCounter == 4'h6; // @[mm2hdmi.scala 72:32]
  wire  _T_69 = outControlCounter == 4'h7; // @[mm2hdmi.scala 75:32]
  wire  _T_70 = outControlCounter == 4'h8; // @[mm2hdmi.scala 78:32]
  wire  _T_71 = outControlCounter == 4'h9; // @[mm2hdmi.scala 81:32]
  wire  _T_72 = outControlCounter == 4'ha; // @[mm2hdmi.scala 84:32]
  wire  _T_73 = outControlCounter == 4'hb; // @[mm2hdmi.scala 87:32]
  wire  _T_74 = outControlCounter == 4'hc; // @[mm2hdmi.scala 90:32]
  wire  _T_75 = outControlCounter == 4'hd; // @[mm2hdmi.scala 93:32]
  wire  _T_76 = outControlCounter == 4'he; // @[mm2hdmi.scala 96:32]
  wire [7:0] _GEN_2 = _T_76 ? regMuxRed14 : regMuxRed15; // @[mm2hdmi.scala 96:42]
  wire [7:0] _GEN_3 = _T_75 ? regMuxRed13 : _GEN_2; // @[mm2hdmi.scala 93:42]
  wire [7:0] _GEN_4 = _T_74 ? regMuxRed12 : _GEN_3; // @[mm2hdmi.scala 90:42]
  wire [7:0] _GEN_5 = _T_73 ? regMuxRed11 : _GEN_4; // @[mm2hdmi.scala 87:42]
  wire [7:0] _GEN_6 = _T_72 ? regMuxRed10 : _GEN_5; // @[mm2hdmi.scala 84:42]
  wire [7:0] _GEN_7 = _T_71 ? regMuxRed9 : _GEN_6; // @[mm2hdmi.scala 81:41]
  wire [7:0] _GEN_8 = _T_70 ? regMuxRed8 : _GEN_7; // @[mm2hdmi.scala 78:41]
  wire [7:0] _GEN_9 = _T_69 ? regMuxRed7 : _GEN_8; // @[mm2hdmi.scala 75:41]
  wire [7:0] _GEN_10 = _T_68 ? regMuxRed6 : _GEN_9; // @[mm2hdmi.scala 72:41]
  wire [7:0] _GEN_11 = _T_67 ? regMuxRed5 : _GEN_10; // @[mm2hdmi.scala 69:41]
  wire [7:0] _GEN_12 = _T_66 ? regMuxRed4 : _GEN_11; // @[mm2hdmi.scala 66:41]
  wire [7:0] _GEN_13 = _T_65 ? regMuxRed3 : _GEN_12; // @[mm2hdmi.scala 63:41]
  wire [7:0] _GEN_14 = _T_64 ? regMuxRed2 : _GEN_13; // @[mm2hdmi.scala 60:41]
  wire [7:0] _GEN_15 = _T_63 ? regMuxRed1 : _GEN_14; // @[mm2hdmi.scala 57:41]
  assign io_red = _T_62 ? regMuxRed0 : _GEN_15; // @[mm2hdmi.scala 55:12 mm2hdmi.scala 58:12 mm2hdmi.scala 61:12 mm2hdmi.scala 64:12 mm2hdmi.scala 67:12 mm2hdmi.scala 70:12 mm2hdmi.scala 73:12 mm2hdmi.scala 76:12 mm2hdmi.scala 79:12 mm2hdmi.scala 82:12 mm2hdmi.scala 85:12 mm2hdmi.scala 88:12 mm2hdmi.scala 91:12 mm2hdmi.scala 94:12 mm2hdmi.scala 97:12 mm2hdmi.scala 100:12]
  assign io_vSync = regVSync; // @[mm2hdmi.scala 104:12]
  assign io_hSync = regNewData; // @[mm2hdmi.scala 103:12]
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  regNewData = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  regRow = _RAND_1[4:0];
  _RAND_2 = {1{`RANDOM}};
  regVSync = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  regData = _RAND_3[15:0];
  _RAND_4 = {1{`RANDOM}};
  regMuxRed0 = _RAND_4[7:0];
  _RAND_5 = {1{`RANDOM}};
  regMuxRed1 = _RAND_5[7:0];
  _RAND_6 = {1{`RANDOM}};
  regMuxRed2 = _RAND_6[7:0];
  _RAND_7 = {1{`RANDOM}};
  regMuxRed3 = _RAND_7[7:0];
  _RAND_8 = {1{`RANDOM}};
  regMuxRed4 = _RAND_8[7:0];
  _RAND_9 = {1{`RANDOM}};
  regMuxRed5 = _RAND_9[7:0];
  _RAND_10 = {1{`RANDOM}};
  regMuxRed6 = _RAND_10[7:0];
  _RAND_11 = {1{`RANDOM}};
  regMuxRed7 = _RAND_11[7:0];
  _RAND_12 = {1{`RANDOM}};
  regMuxRed8 = _RAND_12[7:0];
  _RAND_13 = {1{`RANDOM}};
  regMuxRed9 = _RAND_13[7:0];
  _RAND_14 = {1{`RANDOM}};
  regMuxRed10 = _RAND_14[7:0];
  _RAND_15 = {1{`RANDOM}};
  regMuxRed11 = _RAND_15[7:0];
  _RAND_16 = {1{`RANDOM}};
  regMuxRed12 = _RAND_16[7:0];
  _RAND_17 = {1{`RANDOM}};
  regMuxRed13 = _RAND_17[7:0];
  _RAND_18 = {1{`RANDOM}};
  regMuxRed14 = _RAND_18[7:0];
  _RAND_19 = {1{`RANDOM}};
  regMuxRed15 = _RAND_19[7:0];
  _RAND_20 = {1{`RANDOM}};
  outControlCounter = _RAND_20[3:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
  always @(posedge clock) begin
    regNewData <= io_newData;
    if (reset) begin
      regRow <= 5'h0;
    end else if (io_newData) begin
      regRow <= _T_2;
    end
    if (reset) begin
      regVSync <= 1'h0;
    end else begin
      regVSync <= _GEN_1;
    end
    regData <= io_data;
    if (_T_9) begin
      regMuxRed0 <= 8'h0;
    end else begin
      regMuxRed0 <= 8'hff;
    end
    if (_T_12) begin
      regMuxRed1 <= 8'h0;
    end else begin
      regMuxRed1 <= 8'hff;
    end
    if (_T_15) begin
      regMuxRed2 <= 8'h0;
    end else begin
      regMuxRed2 <= 8'hff;
    end
    if (_T_18) begin
      regMuxRed3 <= 8'h0;
    end else begin
      regMuxRed3 <= 8'hff;
    end
    if (_T_21) begin
      regMuxRed4 <= 8'h0;
    end else begin
      regMuxRed4 <= 8'hff;
    end
    if (_T_24) begin
      regMuxRed5 <= 8'h0;
    end else begin
      regMuxRed5 <= 8'hff;
    end
    if (_T_27) begin
      regMuxRed6 <= 8'h0;
    end else begin
      regMuxRed6 <= 8'hff;
    end
    if (_T_30) begin
      regMuxRed7 <= 8'h0;
    end else begin
      regMuxRed7 <= 8'hff;
    end
    if (_T_33) begin
      regMuxRed8 <= 8'h0;
    end else begin
      regMuxRed8 <= 8'hff;
    end
    if (_T_36) begin
      regMuxRed9 <= 8'h0;
    end else begin
      regMuxRed9 <= 8'hff;
    end
    if (_T_39) begin
      regMuxRed10 <= 8'h0;
    end else begin
      regMuxRed10 <= 8'hff;
    end
    if (_T_42) begin
      regMuxRed11 <= 8'h0;
    end else begin
      regMuxRed11 <= 8'hff;
    end
    if (_T_45) begin
      regMuxRed12 <= 8'h0;
    end else begin
      regMuxRed12 <= 8'hff;
    end
    if (_T_48) begin
      regMuxRed13 <= 8'h0;
    end else begin
      regMuxRed13 <= 8'hff;
    end
    if (_T_51) begin
      regMuxRed14 <= 8'h0;
    end else begin
      regMuxRed14 <= 8'hff;
    end
    if (_T_54) begin
      regMuxRed15 <= 8'h0;
    end else begin
      regMuxRed15 <= 8'hff;
    end
    if (reset) begin
      outControlCounter <= 4'h0;
    end else if (_T_58) begin
      outControlCounter <= 4'h0;
    end else begin
      outControlCounter <= _T_60;
    end
  end
endmodule
