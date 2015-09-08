m, s = gets.split.map &:to_i
small, large = '-1', '-1'
if s == 0 and m == 1 then
  small, large = '0', '0'
elsif s > 0 and m * 9 >= s
  small = '0' * m
  small[0] = '1'
  r = s - 1
  (m-1).downto(1).each do |i|
    if r <= 9 then
      small[i] = (r + '0'.ord).chr
      r = 0
    else
      small[i] = '9'
      r -= 9
    end
  end
  if r > 0 then
    small[0] = (r + '1'.ord).chr
  end
  large = '0' * m
  (0...m).each do |i|
    if s <= 9 then
      large[i] = (s + '0'.ord).chr
      break
    else
      large[i] = '9'
      s -= 9
    end
  end
end
puts small + ' ' + large
