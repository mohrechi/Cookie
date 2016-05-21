n = gets.to_i
terms = Array.new(n + 1, 1)
terms[0] = 2
(2..n).step(3).each do |k|
    terms[k] = (k + 1) / 3 * 2
end
a = 0
b = 1
terms.reverse.each do |t|
    a, b = a * t + b, a
end
ans = 0
while a > 0
    ans += a % 10
    a /= 10
end
puts ans