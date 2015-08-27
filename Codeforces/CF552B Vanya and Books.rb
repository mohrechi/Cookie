n = gets.to_i
ans = 0
len = 1
base = 10
while true
    if n < base then
        ans += (n - base / 10 + 1) * len
        break
    else
        ans += base / 10 * 9 * len
    end
    len += 1
    base *= 10
end
puts ans
