object CF313A {
	def main(argv: Array[String]) {
	    def abs(x: Int): Int = if (x >= 0) x else -x
	    def max(x: Int, y: Int): Int = if (x > y) x else y
	    def sub1(x: Int): Int = x / 10
	    def sub2(x: Int): Int = x / 100 * 10 + x % 10
	    val x = readLine.toInt
	    println(max(x, max(sub1(x), sub2(x))))
	}
}