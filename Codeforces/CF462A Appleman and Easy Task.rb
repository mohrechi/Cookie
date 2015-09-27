STEP_X = [0, 1, 0, -1]
STEP_Y = [1, 0, -1, 0]

n = gets.to_i
b = Array.new n
n.times do |i|
  b[i] = gets
end
valid = true
n.times do |i|
  n.times do |j|
    cnt = 0
    4.times do |k|
      tx = i + STEP_X[k]
      ty = j + STEP_Y[k]
      if 0 <= tx && tx < n then
        if 0 <= ty && ty < n then
          cnt += 1 if b[tx][ty] == 'o'
        end
      end
    end
    valid = false if cnt % 2 == 1
  end
end
if valid then
  puts 'YES'
else
  puts 'NO'
end
