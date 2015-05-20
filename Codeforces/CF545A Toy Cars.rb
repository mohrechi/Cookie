n = gets.to_i
ans = []
(1..n).each do |i|
    row = gets.split.map &:to_i
    ans.push i if not row.include? 1 and not row.include? 3
end
puts ans.size
ans.each do |a|
    print a.to_s + ' '
end
puts