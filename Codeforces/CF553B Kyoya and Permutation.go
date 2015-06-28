package main

import "fmt"

const maxn = 51

func main() {
	var n, k int64
	fmt.Scan(&n, &k)
	fib := make([]int64, maxn)
	fib[0], fib[1] = 1, 1
	for i := int64(2); i < maxn; i++ {
		fib[i] = fib[i-1] + fib[i-2]
	}
	sum := int64(1)
	for i := int64(1); i <= n; i++ {
		if n-i >= 0 && sum+fib[n-i] <= k {
			sum += fib[n-i]
			fmt.Printf("%d %d ", i+1, i)
			i++
		} else {
			fmt.Printf("%d ", i)
		}
	}
}
