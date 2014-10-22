object CF271A {
	def main(argv: Array[String]) {
	    type Set = Int => Boolean
	    def empty(): Set = x => false
	    def singleton(x: Int): Set = y => x == y
	    def union(a: Set, b: Set): Set = x => a(x) || b(x)
	    def judge(x: Int, s: Set): Boolean = {
	        if (x == 0) true
	        else {
	            val y = x % 10
	            if (s(y)) false
	            else judge(x / 10, union(s, singleton(y)))
	        }
	    }
	    def find(x: Int): Int = {
	        if (judge(x, empty())) x
	        else find(x + 1)
	    }
	    println(find(readLine.toInt + 1))
	}
}