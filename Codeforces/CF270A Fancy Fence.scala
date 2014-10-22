object CF270A {
	def main(argv: Array[String]) {
	    def judge(n: Int) {
	        if (n > 0) {
		        if (360 % (180 - readLine.toInt) == 0) println("YES")
		        else println("NO")
		        judge(n - 1)
	        }
	    }
	    judge(readLine.toInt)
	}
}