object CF334B {
	def main(argv: Array[String]) {
	    class Point(x: Int, y: Int) {
	        def x(): Int = x
	        def y(): Int = y
	    }
	    def read(index: Int): List[Point] = {
	        if (index == 8) List()
	        else {
	            val strs = readLine.split(" ")
	            val a = strs(0).toInt
	            val b = strs(1).toInt
	            List(new Point(a, b)) ::: read(index + 1)
	        }
	    }
	    val pointList = read(0)
	    def getX(list: List[Point]): List[Int] = list match {
	        case Nil => List()
	        case head :: tail => List(head.x) ::: getX(tail)
	    }
	    def getY(list: List[Point]): List[Int] = list match {
	        case Nil => List()
	        case head :: tail => List(head.y) ::: getY(tail)
	    }
	    val xList = getX(pointList).sortBy(x => x)
	    val yList = getY(pointList).sortBy(y => y)
	    def getDiffNum(list: List[Int], prev: Int, acc: Map[Int, Int]): Map[Int, Int] = list match {
	        case Nil => acc
	        case head :: tail => {
	            val size = acc.size - 1
	            if (head != acc) getDiffNum(tail, head, acc + (head -> size))
	            else getDiffNum(tail, head, acc)
	        }
	    }
	    val xMap = getDiffNum(xList, -1, Map[Int, Int]())
	    val yMap = getDiffNum(yList, -1, Map[Int, Int]())
	    val xNum = xMap.size
	    val yNum = yMap.size
	    if (xNum != 3 || yNum != 3) {
	        println("ugly")
	    } else {
	        def setVisit(list: List[Point], acc: List[Int]): List[Int] = list match {
	            case Nil => acc
	            case head :: tail => List(xMap(head.x) * 3 + yMap(head.y)) ::: setVisit(tail, acc)
	        }
	        val visit = setVisit(pointList, List())
	        if (visit.sortBy(x => x) == List(0, 1, 2, 3, 5, 6, 7, 8)) println("respectable")
	        else println("ugly")
	    }
	}
}