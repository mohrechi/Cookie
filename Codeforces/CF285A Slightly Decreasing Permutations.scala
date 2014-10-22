object CF285A {
    def main(argv: Array[String]) {
        val in = new java.util.Scanner(System.in)
        val out = new java.io.PrintWriter(System.out)
        val n = in.nextInt
        val k = in.nextInt
        val d = n - k - 1
        val ans = (1 to d) ++ (n until d by -1)
        out.println(ans.mkString(" "))
        out.close
    }
}