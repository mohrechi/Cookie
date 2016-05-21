MAXN = 1001
is_prime = Array.new MAXN, true
primes = []
(2...MAXN).each do |i|
    if is_prime[i] then
        is_prime[i] = true
        primes.push i
        ((i+i)...MAXN).step(i).each do |j|
            is_prime[j] = false
        end
    end
end
t = gets.to_i
t.times do
    n = gets.to_i
    cnt = Array.new n + 1, 0
    cnt[0] = 1
    primes.each do |p|
        break if p > n
        (p..n).each do |i|
            cnt[i] += cnt[i - p]
        end
    end
    puts cnt[n]
end