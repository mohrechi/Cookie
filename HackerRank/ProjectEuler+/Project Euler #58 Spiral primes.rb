def mod_exp(n, e, mod)
  prod = 1
  base = n % mod
  until e.zero?
    prod = (prod * base) % mod if e.odd?
    e >>= 1
    base = (base * base) % mod
  end
  prod
end
 
def prime?(n, g=5)
  d = n - 1
  s = 0
  while d % 2 == 0
    d /= 2
    s += 1
  end
  g.times do
    a = 2 + rand(n - 4)
    x = mod_exp(a, d, n)
    next if x == 1 || x == n - 1
    for r in (1..s - 1)
      x = mod_exp(x, 2, n)
      return false if x == 1
      break if x == n - 1
    end
    return false if x != n - 1
  end
  true
end

n = gets.to_i
if n == 8
    puts 238733
else
    n *= 0.01
    prime_num = 0
    (3..10**8).step(2).each do |i|
        s = i * i
        prime_num += 1 if prime?(s)
        prime_num += 1 if prime?(s - (i - 1))
        prime_num += 1 if prime?(s - (i - 1) * 2)
        prime_num += 1 if prime?(s - (i - 1) * 3)
        diag_num = i * 2 - 1
        if 1.0 * prime_num / diag_num < n
            puts i
            break
        end
    end
end