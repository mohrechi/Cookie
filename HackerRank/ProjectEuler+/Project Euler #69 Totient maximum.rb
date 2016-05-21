MAXN = 100
is_prime = Array.new MAXN, true
primes = [2]
(3...MAXN).step(2).each do |i|
    if is_prime[i] then
        primes.push i
        inc = i << 1
        ((i + inc)...MAXN).step(inc).each do |j|
            is_prime[j] = false
        end
    end
end
t = gets.to_i
t.times do
    n = gets.to_i
    ans = 1
    tmp = 1
    primes.each do |p|
        tmp *= p
        break if tmp >= n
        ans = tmp
    end
    puts ans
end