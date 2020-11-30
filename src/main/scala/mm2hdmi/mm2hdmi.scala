package mm2hdmi

import chisel3._

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
  io.hSync := regHSync

  val regAddress = RegNext(io.address)
  val regData = RegNext(io.data)


  val registerFile = RegInit(VecInit(Seq.fill(16)(23.U(8.W))))
  //val idx = 0.U(3.W)

  for{ 
    idx <- registerFile
    i <- 0 to 15
  } {
    idx := Mux(regData(i) === 0.U, 0.U, 255.U)
    println("regData of " + i.toString + " is " + regData(i).toString)
    println("registerFile of " + i.toString + " is " + idx.toString)
  }
  // val regMuxRed0 = RegNext(Mux(regData(0) === 0.U, 0.U, 255.U))
  // val regMuxRed1 = RegNext(Mux(regData(1) === 0.U, 0.U, 255.U))
  // val regMuxRed2 = RegNext(Mux(regData(2) === 0.U, 0.U, 255.U))
  // val regMuxRed3 = RegNext(Mux(regData(3) === 0.U, 0.U, 255.U))
  // val regMuxRed4 = RegNext(Mux(regData(4) === 0.U, 0.U, 255.U))
  // val regMuxRed5 = RegNext(Mux(regData(5) === 0.U, 0.U, 255.U))
  // val regMuxRed6 = RegNext(Mux(regData(6) === 0.U, 0.U, 255.U))
  // val regMuxRed7 = RegNext(Mux(regData(7) === 0.U, 0.U, 255.U))
  // val regMuxRed8 = RegNext(Mux(regData(8) === 0.U, 0.U, 255.U))
  // val regMuxRed9 = RegNext(Mux(regData(9) === 0.U, 0.U, 255.U))
  // val regMuxRed10 = RegNext(Mux(regData(10) === 0.U, 0.U, 255.U))
  // val regMuxRed11 = RegNext(Mux(regData(11) === 0.U, 0.U, 255.U))
  // val regMuxRed12 = RegNext(Mux(regData(12) === 0.U, 0.U, 255.U))
  // val regMuxRed13 = RegNext(Mux(regData(13) === 0.U, 0.U, 255.U))
  // val regMuxRed14 = RegNext(Mux(regData(14) === 0.U, 0.U, 255.U))
  // val regMuxRed15 = RegNext(Mux(regData(15) === 0.U, 0.U, 255.U))

  val outControlCounter = RegInit(0.U(4.W))
  outControlCounter := Mux(outControlCounter === 15.U || regNewData === 1.U, 0.U, outControlCounter + 1.U)

  for ( selector <- 0 to 15){
    when(outControlCounter === selector.U) {
      io.red := registerFile(selector)
      io.green := registerFile(selector)
      io.blue := registerFile(selector)
    }
    .otherwise {
      io.red := 0.U
      io.green := 0.U
      io.blue := 0.U
    }
  }
  // when (outControlCounter === 0.U) {
  //   io.red := regMuxRed0
  //   io.green := regMuxRed0
  //   io.blue := regMuxRed0
  // }
  // .elsewhen( outControlCounter === 1.U) {
  //   io.red := regMuxRed1
  //   io.green := regMuxRed1
  //   io.blue := regMuxRed1
  // }
  // .elsewhen( outControlCounter === 2.U) {
  //   io.red := regMuxRed2
  //   io.green := regMuxRed2
  //   io.blue := regMuxRed2
  // }
  // .elsewhen( outControlCounter === 3.U) {
  //   io.red := regMuxRed3
  //   io.green := regMuxRed3
  //   io.blue := regMuxRed3
  // }
  // .elsewhen( outControlCounter === 4.U) {
  //   io.red := regMuxRed4
  //   io.green := regMuxRed4
  //   io.blue := regMuxRed4
  // }
  // .elsewhen( outControlCounter === 5.U) {
  //   io.red := regMuxRed5
  //   io.green := regMuxRed5
  //   io.blue := regMuxRed5
  // }
  // .elsewhen( outControlCounter === 6.U) {
  //   io.red := regMuxRed6
  //   io.green := regMuxRed6
  //   io.blue := regMuxRed6
  // }
  // .elsewhen( outControlCounter === 7.U) {
  //   io.red := regMuxRed7
  //   io.green := regMuxRed7
  //   io.blue := regMuxRed7
  // }
  // .elsewhen( outControlCounter === 8.U) {
  //   io.red := regMuxRed8
  //   io.green := regMuxRed8
  //   io.blue := regMuxRed8
  // }
  // .elsewhen( outControlCounter === 9.U) {
  //   io.red := regMuxRed9
  //   io.green := regMuxRed9
  //   io.blue := regMuxRed9
  // }
  // .elsewhen( outControlCounter === 10.U) {
  //   io.red := regMuxRed10
  //   io.green := regMuxRed10
  //   io.blue := regMuxRed10
  // }
  // .elsewhen( outControlCounter === 11.U) {
  //   io.red := regMuxRed11
  //   io.green := regMuxRed11
  //   io.blue := regMuxRed11
  // }
  // .elsewhen( outControlCounter === 12.U) {
  //   io.red := regMuxRed12
  //   io.green := regMuxRed12
  //   io.blue := regMuxRed12
  // }
  // .elsewhen( outControlCounter === 13.U) {
  //   io.red := regMuxRed13
  //   io.green := regMuxRed13
  //   io.blue := regMuxRed13
  // }
  // .elsewhen( outControlCounter === 14.U) {
  //   io.red := regMuxRed14
  //   io.green := regMuxRed14
  //   io.blue := regMuxRed14
  // }
  // .otherwise {
  //   io.red := regMuxRed15
  //   io.green := regMuxRed15
  //   io.blue := regMuxRed15
  // }

  io.vSync := 0.U
}