package main

import "fmt"

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func score(p, t int) int {
	return max(3*p/10, p-p/250*t)
}

func main() {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)
	m := score(a, c)
	v := score(b, d)
	if m > v {
		fmt.Println("Misha")
	} else if m < v {
		fmt.Println("Vasya")
	} else {
		fmt.Println("Tie")
	}
}
