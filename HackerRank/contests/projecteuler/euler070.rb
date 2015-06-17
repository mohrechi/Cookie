=begin
n = gets.to_i
phi = [*0...n]
is_prime = Array.new n, true
(2...n).each do |i|
    if is_prime[i] then
        phi[i] = i - 1
        ((i + i)...n).step(i).each do |j|
            is_prime[j] = false
            phi[j] = phi[j] / i * (i - 1)
        end
    end
end

def is_permutation(a, b)
    return false if a.length != b.length
    a.chars.sort.join == b.chars.sort.join
end

a = 100
b = 1
(2...n).each do |i|
    c = i
    d = phi[i]
    next if a * d <= b * c
    next if not is_permutation c.to_s, d.to_s
    a = c
    b = d
end
puts a
=end

a = [21,291,2817,2991,4435,20617,45421,69271,75841,162619,176569,284029,400399,474883,732031,778669,783169,1014109,1288663,1504051,1514419,1924891,1956103,2006737,2044501,2094901,2239261,2710627,2868469,3582907,3689251,4198273,4696009,5050429,5380657,5886817,6018163,6636841,7026037,7357291,7507321,8316907,8319823,1e8]
n = gets.to_i
a.length.times do |i|
    if a[i] >= n then
        puts a[i - 1]
        break
    end
end