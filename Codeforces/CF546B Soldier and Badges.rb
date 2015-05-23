n = gets.to_i
a = gets.split.map &:to_i
a.sort!
ans = 0
last = 0
a.each do |x|
    while x <= last
        ans += 1
        x += 1
    end
    last = x
end
puts ans