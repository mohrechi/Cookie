x := File standardInput readLine asNumber
odd := 0
even := 0
for (i, 1, x,
    if (x % i == 0,
        if (i % 2 == 1,
            odd = odd + 1,
            even = even + 1
        )
    )
)
(odd == even) ifTrue("yes" println) ifFalse ("no" println)
