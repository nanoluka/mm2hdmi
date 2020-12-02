package mm2hdmi

import chisel3._

/**
  * Interface a memory section to HDMI
  */
class MM2hdmi extends Module {
  val io = IO(new Bundle {
    val data          = Input(UInt(16.W))
    val newData       = Input(UInt(1.W))
    val red           = Output(UInt(8.W))
    val vSync         = Output(UInt(1.W))
    val hSync         = Output(UInt(1.W))
  })

  val regNewData = RegNext(io.newData)

  val regRow = RegInit(0.U(5.W))
  when(regNewData === 1.U) {
    regRow := regRow + 1.U
  }

  val regVSync = RegInit(0.U(1.W))
  when(regRow === 31.U && io.newData === 1.U) {
    regVSync := regVSync + 1.U
  }
  .otherwise{
    regVSync := 0.U
  }

  val regData = RegNext(io.data)

  val regMuxRed0 = RegNext(Mux(regData(0) === 0.U, 0.U, 255.U))
  val regMuxRed1 = RegNext(Mux(regData(1) === 0.U, 0.U, 255.U))
  val regMuxRed2 = RegNext(Mux(regData(2) === 0.U, 0.U, 255.U))
  val regMuxRed3 = RegNext(Mux(regData(3) === 0.U, 0.U, 255.U))
  val regMuxRed4 = RegNext(Mux(regData(4) === 0.U, 0.U, 255.U))
  val regMuxRed5 = RegNext(Mux(regData(5) === 0.U, 0.U, 255.U))
  val regMuxRed6 = RegNext(Mux(regData(6) === 0.U, 0.U, 255.U))
  val regMuxRed7 = RegNext(Mux(regData(7) === 0.U, 0.U, 255.U))
  val regMuxRed8 = RegNext(Mux(regData(8) === 0.U, 0.U, 255.U))
  val regMuxRed9 = RegNext(Mux(regData(9) === 0.U, 0.U, 255.U))
  val regMuxRed10 = RegNext(Mux(regData(10) === 0.U, 0.U, 255.U))
  val regMuxRed11 = RegNext(Mux(regData(11) === 0.U, 0.U, 255.U))
  val regMuxRed12 = RegNext(Mux(regData(12) === 0.U, 0.U, 255.U))
  val regMuxRed13 = RegNext(Mux(regData(13) === 0.U, 0.U, 255.U))
  val regMuxRed14 = RegNext(Mux(regData(14) === 0.U, 0.U, 255.U))
  val regMuxRed15 = RegNext(Mux(regData(15) === 0.U, 0.U, 255.U))

  val outControlCounter = RegInit(0.U(4.W))
  outControlCounter := Mux(outControlCounter === 15.U || regNewData === 1.U, 0.U, outControlCounter + 1.U)

  when (outControlCounter === 0.U) {
    io.red := regMuxRed0
  }
  .elsewhen( outControlCounter === 1.U) {
    io.red := regMuxRed1
  }
  .elsewhen( outControlCounter === 2.U) {
    io.red := regMuxRed2
  }
  .elsewhen( outControlCounter === 3.U) {
    io.red := regMuxRed3
  }
  .elsewhen( outControlCounter === 4.U) {
    io.red := regMuxRed4
  }
  .elsewhen( outControlCounter === 5.U) {
    io.red := regMuxRed5
  }
  .elsewhen( outControlCounter === 6.U) {
    io.red := regMuxRed6
  }
  .elsewhen( outControlCounter === 7.U) {
    io.red := regMuxRed7
  }
  .elsewhen( outControlCounter === 8.U) {
    io.red := regMuxRed8
  }
  .elsewhen( outControlCounter === 9.U) {
    io.red := regMuxRed9
  }
  .elsewhen( outControlCounter === 10.U) {
    io.red := regMuxRed10
  }
  .elsewhen( outControlCounter === 11.U) {
    io.red := regMuxRed11
  }
  .elsewhen( outControlCounter === 12.U) {
    io.red := regMuxRed12
  }
  .elsewhen( outControlCounter === 13.U) {
    io.red := regMuxRed13
  }
  .elsewhen( outControlCounter === 14.U) {
    io.red := regMuxRed14
  }
  .otherwise {
    io.red := regMuxRed15
  }

  io.hSync := regNewData
  io.vSync := regVSync
}