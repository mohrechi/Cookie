n, k = gets.split.map {|x| x.to_i}
cubes = Hash.new []
n.times do |x|
  x = x ** 3
  num = Array.new(10, 0)
  h = 0
  t = x
  while t > 0
    num[t % 10] += 1
    h += 1
    t /= 10
  end
  num.each do |m|
    h = h * 20 + m
  end
  cubes[h] += [x]
end
ans = []
cubes.each do |key, cube|
  if cube.size == k
    ans.push cube.first
  end
end
puts ans.sort