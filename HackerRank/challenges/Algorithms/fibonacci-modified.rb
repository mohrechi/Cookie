a, b, n = gets.split.map &:to_i
c = 0
(3..n).each do
    c = a + b * b
    a = b
    b = c
end
puts c
