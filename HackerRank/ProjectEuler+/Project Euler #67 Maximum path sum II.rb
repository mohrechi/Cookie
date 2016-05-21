t = gets.to_i
t.times do
    n = gets.to_i
    a = []
    n.times do
        a.push gets.split.map &:to_i
    end
    (1...n).each do |i|
        a[i][0] += a[i - 1][0]
        (1...i).each do |j|
            a[i][j] += [a[i - 1][j - 1], a[i - 1][j]].max
        end
        a[i][i] += a[i - 1][i - 1]
    end
    a = a[-1]
    ans = a[0]
    (1...n).each do |i|
        ans = a[i] if a[i] > ans
    end
    puts ans
end