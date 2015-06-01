n = gets.to_i
a = Array.new n
n.times do |i|
    a[i] = gets.split.map &:to_i
    n.times do |j|
        if i > 0 and j > 0
            a[i][j] += [a[i - 1][j], a[i][j - 1]].min
        elsif i > 0
            a[i][j] += a[i - 1][j]
        elsif j > 0
            a[i][j] += a[i][j - 1]
        end
    end
end
puts a[n - 1][n - 1]