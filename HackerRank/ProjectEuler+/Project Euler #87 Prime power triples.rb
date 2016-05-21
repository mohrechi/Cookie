maxn = 1e7.to_i + 1
maxp = 1e4.to_i
is_prime = Array.new maxp, true
primes = []
(2...maxp).each do |i|
    if is_prime[i] then
        primes.push i
        ((i+i)...maxp).step(i).each do |j|
            is_prime[j] = false
        end
    end
end
nums = Array.new maxn, 0
primes.each do |a|
    ta = a * a
    break if ta >= maxn
    primes.each do |b|
        tb = ta + b ** 3
        break if tb >= maxn
        primes.each do |c|
            tc = tb + c ** 4
            break if tc >= maxn
            nums[tc] = 1
        end
    end
end
(1...maxn).each do |i|
    nums[i] += nums[i - 1]
end
t = gets.to_i
t.times do
    n = gets.to_i
    puts nums[n]
end
