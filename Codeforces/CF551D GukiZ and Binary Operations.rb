ans = 0
def fib(n, m)
    i = 0
    a, b, c, d = 1, 1, 1, 0
    aa, bb, cc, dd = 1, 0, 0, 1
    while (1 << i) <= n
        if (n & (1 << i)) > 0 then
            aa, bb, cc, dd = (aa*a+bb*c)%m, (aa*b+bb*d)%m, (cc*a+dd*c)%m, (cc*b+dd*d)%m
        end
        a, b, c, d = (a*a+b*c)%m, (a*b+b*d)%m, (c*a+d*c)%m, (c*b+d*d)%m
        i += 1
    end
    (aa + bb) % m
end
def pow(x, y, m)
    i = 0
    ret = 1
    while (1 << i) <= y
        if (y & (1 << i)) > 0 then
            ret = ret * x % m
        end
        x = x * x % m
        i += 1
    end
    ret
end
n, k, l, m = gets.split.map &:to_i
if k < 2 ** l then
    ans = 1 % m
    num0 = fib(n, m)
    num1 = (pow(2, n, m) - num0 + m) % m
    l.times do |i|
        if (k & (1 << i)) == 0 then
            ans = ans * num0 % m
        else
            ans = ans * num1 % m
        end
    end
end
puts ans