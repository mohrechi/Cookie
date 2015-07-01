n, w = gets.split.map &:to_i
a = gets.split.map &:to_i
a = a.sort
x = a[0...n].min
y = a[n...(2*n)].min
puts [[2*x, y].min * 1.5 * n, w].min
