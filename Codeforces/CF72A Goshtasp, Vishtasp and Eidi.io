n := File standardInput readLine asNumber
m := n
is_first := 1
while (n > 0,
    for (x, n, 1, -1,
        is_prime := 1;
        for (i, 2, x - 1,
            if (x % i == 0,
                is_prime := 0;
                break;
            )
        )
        if (is_prime == 1,
            if (is_first == 0,
                "+" print
            )
            is_first := 0
            n := n - x
            x print
            break
        )
    )
)
"=" print
m println
