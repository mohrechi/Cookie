n, m = gets.split.map &:to_i
a = gets.split.map &:to_i
l, r = 0, 2e14.to_i
ans = r
while l <= r
    mid = (l + r) >> 1
    b = a[0]
    i, j, t = 0, -1, 0
    while i < n and j < m
        if b == 0 then
            i += 1
            b = a[i]
            t -= 1
        else
            if t <= 0 then
                j += 1
                t = mid - i - 1
            else
                if t < b then
                    b -= t
                    t = 0
                else
                    t -= b
                    b = 0
                end
            end
        end
    end
    if i == n then
        r = mid - 1
        ans = [ans, mid].min
    else
        l = mid + 1
    end
end
puts ans
