package mm2hdmi

import chisel3._

class MyMux extends Module {
  val io = IO(new Bundle{
    val selector = Input(Bool())
    val input1 = Input(UInt(8.W))
    val input2 = Input(UInt(8.W))
    val output = Output(UInt(8.W))
  })

  io.output := Mux(io.selector, io.input1, io.input2)
}

class MyRegs extends Module {
  val io = IO(new Bundle{
    val input = Input(UInt(8.W))
    val output = Output(UInt(8.W))
  })

  io.output := RegNext(io.input)
}

class MyMux16 extends Module {
  val io = IO(new Bundle{
    val selector = Input(UInt(4.W))
    val inputs = Input(Vec(16, UInt(8.W)))
    val output = Output(UInt(8.W))
  })

  for (i <- 0 to 15) {
    when(io.selector === i.U) {
      io.output := io.inputs(i)
    }
    .otherwise {
      io.output := 10.U
    }
  }
}

/**
  * Interface a memory section to HDMI
  */
class MM2hdmi extends Module {
  val io = IO(new Bundle {
    val data          = Input(UInt(16.W))
    val address       = Input(UInt(16.W))
    val newData       = Input(UInt(1.W))
    val red           = Output(UInt(8.W))
    val blue          = Output(UInt(8.W))
    val green         = Output(UInt(8.W))
    val vSync         = Output(UInt(1.W))
    val hSync         = Output(UInt(1.W))
  })

  var j = 0
  var i = 0
  var k = 16384



  val regNewData = RegNext(io.newData)

  val regHSync = RegInit(0.U(1.W))
  regHSync := regHSync + 1.U
  

  val regAddress = RegNext(io.address)
  val regData = RegNext(io.data)

  //val registerFile = RegInit(VecInit(Seq.fill(16){0.U(8.W)}))
  val regs = VecInit(Seq.fill(16){Module(new MyRegs()).io})
  val muxes = VecInit(Seq.fill(16){Module(new MyMux()).io})
  val mux16 = Module(new MyMux16())

  val outControlCounter = RegInit(0.U(4.W))
  outControlCounter := Mux(outControlCounter === 15.U || regNewData === 1.U, 0.U, outControlCounter + 1.U)

  io.hSync := regHSync
  io.vSync := 0.U

  for{ 
    idx <- regs//registerFile
    i <- 0 to 15
  } {
        muxes(i).input1 := 0.U
        muxes(i).input2 := 255.U
        muxes(i).selector := regData(i) === 0.U
        idx := muxes(i).output
    //println("regData of " + i.toString + " is " + regData(i).toString)
    //println("registerFile of " + i.toString + " is " + idx.toString)

        mux16.io.inputs(i) := idx
        mux16.io.selector := outControlCounter
        io.red := mux16.io.output
        io.green := mux16.io.output
        io.blue := mux16.io.output
      //   when(outControlCounter === i.U) {
      // //println("selector is " + selector.toString + " and " + outControlCounter.toString)
      //     io.red := idx//registerFile(i)
      //     io.green := idx//registerFile(i)
      //     io.blue := idx//registerFile(i)
      //   }
      //   .otherwise {
      //     io.red := idx//registerFile(i)
      //     io.green := idx//registerFile(i)
      //     io.blue := idx//registerFile(i)
      //   }
    }
}