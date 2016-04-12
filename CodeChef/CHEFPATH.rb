t = gets.to_i
t.times do
    n, m = gets.split.map &:to_i
    n, m = m, n if n > m
    if n == 1 and m != 2
        puts "No"
    elsif n.even? or m.even? then
        puts "Yes"
    else 
        puts "No" 
    end
end
