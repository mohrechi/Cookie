object CF272A {
    def main(argv: Array[String]) {
        val n = readInt
        val str = readLine.split(" ")
        def readSum(i: Int, acc: Int): Int = {
            if (i == n) acc
            else readSum(i + 1, acc + str(i).toInt)
        }
        val sum = readSum(0, 0)
        def findAns(i: Int, acc: Int): Int = {
            if (i == 6) acc
            else {
                if ((sum + i) % (n + 1) != 1) findAns(i + 1, acc + 1)
                else findAns(i + 1, acc)
            }
        }
        println(findAns(1, 0))
    }
}