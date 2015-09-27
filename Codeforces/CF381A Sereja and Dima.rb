n = gets.to_i
a = gets.split.map &:to_i
l = 0
r = n - 1
s = [0, 0]
turn = 0
while l <= r do
    if a[l] >= a[r] then
        s[turn] += a[l]
        l += 1
    else
        s[turn] += a[r]
        r -= 1
    end
    turn = 1 - turn
end
puts s[0].to_s + ' ' + s[1].to_s
