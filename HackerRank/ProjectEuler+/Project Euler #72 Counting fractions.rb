MAXN = 1000001
phi = Array.new MAXN, 0
(2...MAXN).each do |i|
    phi[i] = i
end
(2...MAXN).each do |i|
    if phi[i] == i
        phi[i] = i - 1
        ((i + i)...MAXN).step(i).each do |j|
            phi[j] = phi[j] / i * (i - 1)
        end
    end
end
(2...MAXN).each do |i|
    phi[i] += phi[i - 1]
end
t = gets.to_i
t.times do
    n = gets.to_i
    puts phi[n]
end