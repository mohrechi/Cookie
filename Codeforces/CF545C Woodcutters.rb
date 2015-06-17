n = gets.to_i
x = Array.new(n)
h = Array.new(n)
n.times do |i|
    x[i], h[i] = gets.split.map(&:to_i)
end
ans = 2
(1..n-2).each do |i|
    if x[i] - h[i] > x[i - 1]
        ans += 1
    elsif x[i] + h[i] < x[i + 1] 
        ans += 1
        x[i] += h[i]
    end
end
puts [ans, n].min