s := File standardInput readLine
cnt := 0
for (i, 0, s size - 1,
    if (s asNumber % s slice(i, i + 1) asNumber == 0,
        cnt = cnt + 1
    )
)
if (cnt == 0,
    "upset" println,
    if (cnt == s size,
        "happier" println,
        "happy" println
    )
)
