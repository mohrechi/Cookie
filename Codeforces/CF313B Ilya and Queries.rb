s = gets
n = s.length
sum = Array.new n + 1, 0
(2..n).each do |i|
  sum[i] += sum[i - 1]
  if s[i - 1] == s[i - 2]
    sum[i] += 1
  end
end
m = gets.to_i
m.times do
  l, r = gets.split.map &:to_i
  puts sum[r] - sum[l]
end
