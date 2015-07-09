n = gets.to_i
n.times do
    s = gets.gsub /\r\n|\r|\n/, ''
    is_f, is_r = false, false
    if s.length >= 5
        is_f = s[-5..-1] == 'lala.'
        is_r = s[0...5] == 'miao.'
    end
    if is_f and not is_r then
        puts "Freda's"
    elsif not is_f and is_r then
        puts "Rainbow's"
    else
        puts "OMG>.< I don't know!"
    end
end
