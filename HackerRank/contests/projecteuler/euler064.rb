n = gets.to_i
ans = 0
(2..n).each do |x|
  y = Math.sqrt(x).to_i
  next if x == y * y
  a, b = y, 1
  vals = Hash.new
  loop do
    h = a * 30000 + b
    break if vals.has_key? h
    vals[h] = 0
    l = ((x - a * a) / b).abs
    a, b = (a - (a + y) / l * l).abs, l
  end
  ans += 1 if vals.size.odd?
end
puts ans