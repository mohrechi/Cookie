t = gets.to_i
t.times do
    b = gets.split.map &:to_i
    k = gets.to_i
    s = 0
    b.each do |x|
        s += x if x < k
        s += k - 1 if x >= k
    end
    puts s + 1
end
