def gcd(a, b)
    if b == 0 then a else gcd b, a % b end
end

t = gets.to_i
t.times do
    a, b, n = gets.split.map &:to_i
    la, lb = 0, 1
    ra, rb = 1, 1
    aa, ab = 0, 1
    cnt = 0
    while true
        if ra == a and rb == b
            k = (n - lb) / b
            ma = la + k * a
            mb = lb + k * b
            cnt += 1 if k == 0
            break if cnt > 2
        else
            ma = la + ra
            mb = lb + rb
        end
        g = gcd ma, mb
        ma /= g
        mb /= g
        if ma * b < mb * a then
            la, lb = ma, mb
            aa, ab = ma, mb if ma * ab > mb * aa and mb <= n
        else
            ra, rb = ma, mb
        end
        break if lb > n or rb > n
    end
    puts aa.to_s + ' ' + ab.to_s
end