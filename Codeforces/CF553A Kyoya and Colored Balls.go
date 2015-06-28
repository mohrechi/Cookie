package main

import "fmt"

const mod = 1000000007

func fastPow(x, y int64) int64 {
	var ret int64 = 1
	for i := uint(0); (1 << i) <= y; i++ {
		if (y & (1 << i)) > 0 {
			ret = ret * x % mod
		}
		x = x * x % mod
	}
	return ret
}

func main() {
	var k int
	fmt.Scan(&k)
	c := make([]int64, k)
	for i := 0; i < k; i++ {
		fmt.Scan(&c[i])
		if i > 0 {
			c[i] += c[i-1]
		}
	}
	var m = c[k-1]
	fact := make([]int64, c[k-1])
	fact[0] = 1
	for i := int64(1); i < m; i++ {
		fact[i] = fact[i-1] * i % mod
	}
	ans := int64(1)
	var n int64
	for i := 1; i < k; i++ {
		n = c[i] - 1
		m = c[i] - c[i-1] - 1
		ans = ans * fact[n] % mod * fastPow(fact[m]*fact[n-m]%mod, mod-2) % mod
	}
	fmt.Println(ans)
}
