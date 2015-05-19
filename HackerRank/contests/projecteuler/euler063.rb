n = gets.to_i
def cnt(x)
  if x == 0 then 0 else 1 + cnt(x / 10) end
end
10000.times do |x|
  x **= n
  c = cnt(x)
  break if c > n
  puts x if c == n
end