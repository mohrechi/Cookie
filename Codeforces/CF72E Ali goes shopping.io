s := File standardInput readLine
ans := s
max_cnt := 1
for (i, 0, s size - 1,
    sub := ""
    for (j, i, s size - 1,
        sub = sub .. s slice(j, j + 1)
        cnt := 0
        l := j - i + 1
        for (k, 0, s size - l,
            if (s slice(k, k + l) == sub,
                cnt = cnt + 1
            )
        )
        if (cnt > max_cnt,
            max_cnt = cnt
            ans = sub,
            if (cnt == max_cnt,
                if (l > ans size,
                    ans = sub,
                    if (l == ans size,
                        if (sub > ans,
                            ans = sub
                        )
                    )
                )
            )
        )
    )
)
ans println
