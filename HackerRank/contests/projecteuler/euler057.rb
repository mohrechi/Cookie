n = gets.to_i
x = 3
y = 2
(2..n).each do |i|
    x, y = x + y + y, x + y
    puts i if x.to_s.size > y.to_s.size
end