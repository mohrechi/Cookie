n = gets.to_i
k1 = gets.split.map &:to_i
k2 = gets.split.map &:to_i
k1.shift
k2.shift
idx = Hash.new
index = 0
k1.each do |x|
    index += 1
    idx[x] = index
end
k2.each do |x|
    index += 1
    idx[x] = index
end
states = Hash.new(0)
index = 0
loop do
    a = k1.shift rescue nil
    b = k2.shift rescue nil
    if a.nil?
        puts index.to_s + ' 2'
        exit
    end
    if b.nil?
        puts index.to_s + ' 1'
        exit
    end
    if a > b
        k1 << b << a
    else
        k2 << a << b
    end
    state = 0
    k1.each do |x|
        state = state * 11 + idx[x]
    end
    state = state * 11 + 10
    k2.each do |x|
        state = state * 11 + idx[x]
    end
    break if states.has_key? state
    states[state] = 0
    index += 1
end
puts '-1'