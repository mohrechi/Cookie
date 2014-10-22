object CF334A {
    def main(argv: Array[String]) {
        val n = readLine.toInt
        def output(index: Int): Unit = {
            val a = index
            val b = n * n - index + 1
            if (index % (n >> 1) == 0) {
                if (index == (n * n) >> 1) {
                    println(a + " " + b)
                } else {
                    println(a + " " + b)
                    output(index + 1)
                }
            } else {
                print(a + " " + b + " ")
                output(index + 1)
            }
        }
        output(1)
    }
}