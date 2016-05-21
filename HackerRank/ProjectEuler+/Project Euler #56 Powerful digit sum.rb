n = gets.to_i
max_sum = 0
(1..n).each do |a|
    (1..n).each do |b|
        x = a ** b
        t = 0
        while x > 0 do
            x, r = x.divmod(10)
            t += r
        end
        max_sum = [max_sum, t].max
    end
end
puts max_sum