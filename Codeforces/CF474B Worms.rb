n = gets.to_i
a = gets.split.map &:to_i
m = gets.to_i
q = gets.split.map &:to_i
(1...n).each do |i|
    a[i] += a[i - 1]
end
a = [0] + a
n.downto(1).each do |i|
    a[i] = a[i - 1] + 1
end
q.each do |x|
    ans = 1
    l, r = 1, n
    while l <= r do
        mid = (l + r) / 2
        if x >= a[mid] then
            l = mid + 1
            ans = [ans, mid].max
        else
            r = mid - 1
        end
    end
    puts ans
end
