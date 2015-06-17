n = gets.to_i
a = gets.split.map &:to_i

def find_left(a)
    s = []
    r = Array.new(a.length)
    (0...a.length).each do |i|
        s.pop while s.length > 0 and a[s[-1]] >= a[i]
        if s.length == 0 then r[i] = i + 1 else r[i] = i - s[-1] end
        s.push i
    end
    r
end

left = find_left a
right = (find_left a.reverse).reverse
ans = Array.new(n, a.min)
(0...n).each do |i|
    v = left[i] + right[i] - 2
    ans[v] = a[i] if a[i] > ans[v]
end
(n-2).downto(0) do |i|
    ans[i] = ans[i + 1] if ans[i + 1] > ans[i]
end
ans.each do |x|
    print x
    print ' '
end
puts