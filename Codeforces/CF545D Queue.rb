n = gets.to_i
t = gets.split.map(&:to_i)
sum = 0
ans = 0
t.sort.each do |x|
    if x >= sum
        sum += x
        ans += 1
    end
end
puts ans
