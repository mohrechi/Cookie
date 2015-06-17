s = gets
t = gets
z = s.split('').zip(t.split(''))
dist = 0
z.each do |si, ti|
    dist += 1 if si != ti
end
if dist.odd?
    puts 'impossible'
else
    dist /= 2
    z.each do |si, ti|
        if si == ti
            print si
        else
            if dist > 0
                dist -= 1
                print si
            else
                print ti
            end
        end
    end
    puts
end