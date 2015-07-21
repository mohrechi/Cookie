package main

import "fmt"

var output chan int

func cnt(rows []string, idx int) {
	c := 0
	for i := 0; i < len(rows); i++ {
		if rows[i] == rows[idx] {
			c++
		}
	}
	output <- c
}

func main() {
	var n int
	fmt.Scan(&n)
	rows := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&rows[i])
	}
	output = make(chan int, n)
	for i := 0; i < n; i++ {
		go cnt(rows, i)
	}
	ans := 0
	for i := 0; i < n; i++ {
		tmp := <-output
		if tmp > ans {
			ans = tmp
		}
	}
	fmt.Println(ans)
}
