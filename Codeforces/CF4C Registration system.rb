n = gets.to_i
names = {}
n.times do
    name = gets.strip
    if names.has_key? name then
        names[name] += 1
        puts name + names[name].to_s
    else
        names[name] = 0
        puts 'OK'
    end
end
