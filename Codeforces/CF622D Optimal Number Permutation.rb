n = gets.to_i
a = []
if n.odd? then
    1.step(n, 2) do |i|
        a.push i
    end
    (n-2).step(1, -2) do |i|
        a.push i
    end
    a.push n
    2.step(n, 2) do |i|
        a.push i
    end
    (n-1).step(2, -2) do |i|
        a.push i
    end
else
    1.step(n, 2) do |i|
        a.push i
    end
    (n-1).step(1, -2) do |i|
        a.push i
    end
    a.push n
    2.step(n, 2) do |i|
        a.push i
    end
    (n-2).step(2, -2) do |i|
        a.push i
    end
end
puts a.join(' ')
