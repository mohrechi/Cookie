concat := method(a, b, a .. b)
reverse := method(x, x asMutable reverse)
substr := method(x, a, b, c,
    if (c isNil,
        c = 1
    )
    s := "" asMutable
    for (i, a - 1, b - 1, c,
        s append (x at(i))
    )
    return s
)
line := File standardInput readLine
codes := list()
line split("\"") foreach (i, v,
    codes append(if (i % 2 == 0, v asLowercase, "\"" .. v .. "\""))
)
("\"" .. doString(codes join("")) .. "\"") println
