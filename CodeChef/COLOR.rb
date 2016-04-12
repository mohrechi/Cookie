t = gets.to_i
t.times do
    n = gets.to_i
    s = gets
    puts n - [s.count('R'), s.count('G'), s.count('B')].max
end
