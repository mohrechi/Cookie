object CF281A {
    def main(argv: Array[String]) {
        def func(s: String): String = s.head.toUpper + s.tail
        println(func(readLine))
    }
}