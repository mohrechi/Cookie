t = gets.to_i
$mod = (1e9 + 7).to_i

def mod_exp(x, y)
    return 1 if y == 0
    e = mod_exp x * x % $mod, y >> 1
    if y % 2 == 1 then x * e % $mod else e end
end

t.times do
    n, k = gets.split.map &:to_i
    puts k * mod_exp(k - 1, n - 1) % $mod
end
