n := File standardInput readLine asNumber
fib := method(a, b, n,
    if (n == 1,
        return b,
        return fib(b, a + b, n - 1)
    )
)
fib(1, 1, n) println
