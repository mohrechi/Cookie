n, t, c = gets.split.map &:to_i
s = gets.split.map &:to_i
s.push t + 1
l = 0
ans = 0
(n+1).times do |i|
  if s[i] > t then
    if i - l >= c then
      ans += i - l + 1 - c
    end
    l = i + 1
  end
end
puts ans
