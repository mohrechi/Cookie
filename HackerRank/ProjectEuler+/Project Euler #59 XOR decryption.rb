n = gets.to_i
nums = gets.split.map {|x| x.to_i}
def valid(v)
    return true if 'a'.ord <= v and v <= 'z'.ord
    return true if 'A'.ord <= v and v <= 'Z'.ord
    return true if '0'.ord <= v and v <= '9'.ord
    return true if ['(', ')', ';', ':', ',', '.', '\'', '?', '-', '!', ' '].map {|x| x.ord}.include? v
    return false
end
('a'.ord..'z'.ord).each do |a|
    ('a'.ord..'z'.ord).each do |b|
        ('a'.ord..'z'.ord).each do |c|
            key = [a, b, c]
            flag = true
            nums.size.times do |i|
                unless valid nums[i] ^ key[i % 3]
                    flag = false
                    break
                end
            end
            if flag
                puts a.chr + b.chr + c.chr
            end
        end
    end
end