// See README.md for license details.

package mm2hdmi

import java.io.File

import chisel3.iotesters
import chisel3.iotesters.{ChiselFlatSpec, Driver, PeekPokeTester}

class MM2hdmiUnitTester(c: MM2hdmi) extends PeekPokeTester(c) {
  /**
    * compute the mm2hdmi and the number of steps it should take to do it
    *
    * @param a positive integer
    * @param b positive integer
    * @return the GCD of a and b
    */
  def computeRGB(d: Int): (Int, Int, Int) = {
    var data = d
    var R = 0
    var vSync = 0
    var hSync = 0

    if ( d == 0 ) {
        R = 0
      }
      else {
        R = 255
      }
    
    (R, vSync, hSync)
  }

  def toBinary(n: Int): String = n match {
    case 0|1 => s"$n"
    case _   => s"${toBinary(n/2)}${n%2}"
  }

  def singleOutTheData(data: Int): String = {

    var intBinary = toBinary(data).toInt
    var dBinary = "%016d".format(intBinary)
    dBinary.reverse
  }

  private val mm2hdmi = c


    for (i <- 1 to 100) {
      poke(mm2hdmi.io.data, i)
      poke(mm2hdmi.io.newData, 1)
      step(1)
      poke(mm2hdmi.io.newData, 0)

      var dBits = singleOutTheData(i)
      //printf("i je %d\n", i)
      //printf("i string je %s\n", dBits)
      for ( j <- dBits) {
        step(1)
        val (expectedR, expectedVSync, expectedHSync) = computeRGB((j.toInt)-48)
        //printf("dbits od j je %d\n", (j.toInt)-48)
        expect(mm2hdmi.io.red, expectedR)
      }
      
    }

}

/**
  * This is a trivial example of how to run this Specification
  * From within sbt use:
  * {{{
  * testOnly mm2hdmi.MM2hdmiTester
  * }}}
  * From a terminal shell use:
  * {{{
  * sbt 'testOnly mm2hdmi.MM2hdmiTester'
  * }}}
  */
class MM2hdmiTester extends ChiselFlatSpec {
  private val backendNames = if(firrtl.FileUtils.isCommandAvailable(Seq("verilator", "--version"))) {
    Array("firrtl", "verilator")
  }
  else {
    Array("firrtl")
  }
  for ( backendName <- backendNames ) {
    "MM2hdmi" should s"calculate proper greatest common denominator (with $backendName)" in {
      Driver(() => new MM2hdmi, backendName) {
        c => new MM2hdmiUnitTester(c)
      } should be (true)
    }
  }

  "Basic test using Driver.execute" should "be used as an alternative way to run specification" in {
    iotesters.Driver.execute(Array(), () => new MM2hdmi) {
      c => new MM2hdmiUnitTester(c)
    } should be (true)
  }

  if(backendNames.contains("verilator")) {
    "using --backend-name verilator" should "be an alternative way to run using verilator" in {
      iotesters.Driver.execute(Array("--backend-name", "verilator"), () => new MM2hdmi) {
        c => new MM2hdmiUnitTester(c)
      } should be(true)
    }
  }

  "running with --is-verbose" should "show more about what's going on in your tester" in {
    iotesters.Driver.execute(Array("--is-verbose"), () => new MM2hdmi) {
      c => new MM2hdmiUnitTester(c)
    } should be(true)
  }

  /**
    * By default verilator backend produces vcd file, and firrtl and treadle backends do not.
    * Following examples show you how to turn on vcd for firrtl and treadle and how to turn it off for verilator
    */

  "running with --generate-vcd-output on" should "create a vcd file from your test" in {
    iotesters.Driver.execute(
      Array("--generate-vcd-output", "on", "--target-dir", "test_run_dir/make_a_vcd", "--top-name", "make_a_vcd"),
      () => new MM2hdmi
    ) {

      c => new MM2hdmiUnitTester(c)
    } should be(true)

    new File("test_run_dir/make_a_vcd/MM2hdmi.vcd").exists should be (true)
  }

  "running with --generate-vcd-output off" should "not create a vcd file from your test" in {
    iotesters.Driver.execute(
      Array("--generate-vcd-output", "off", "--target-dir", "test_run_dir/make_no_vcd", "--top-name", "make_no_vcd",
      "--backend-name", "verilator"),
      () => new MM2hdmi
    ) {

      c => new MM2hdmiUnitTester(c)
    } should be(true)

    new File("test_run_dir/make_no_vcd/make_a_vcd.vcd").exists should be (false)

  }

}
