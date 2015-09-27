n = gets.to_i
a = gets.split.map &:to_i
l = n
(1...n).each do |i|
  if a[i] < a[i - 1] then
    l = i
    break
  end
end
if l == n then
  puts 'yes'
  puts '1 1'
else
  r = n
  (l...n).each do |i|
    if a[i] > a[i - 1] then
      r = i
      break
    end
  end
  flag = true
  (0...(l-1)).each do |i|
    if a[i] > a[r - 1] then
      flag = false
      break
    end
  end
  if flag then
    (r...n).each do |i|
      if a[i] < a[i - 1] || a[i] < a[l-1] then
        flag = false
        break
      end
    end
  end
  if flag then
    puts 'yes'
    puts l.to_s + ' ' + r.to_s
  else
    puts 'no'
  end
end
