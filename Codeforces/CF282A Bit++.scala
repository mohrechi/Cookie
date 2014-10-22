object CF282A {
    def main(argc: Array[String]) {
        def deal(left: Int, x: Int) : Int = {
            if (left == 0) x
            else {
                readLine match {
                    case "X++" | "++X" => deal(left - 1, x + 1)
                    case "X--" | "--X" => deal(left - 1, x - 1)
                }
            }
        }
        println(deal(readLine.toInt, 0))
    }
}
