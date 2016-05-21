def rev(x, y=0)
	if x == 0 then y else rev x / 10, y * 10 + x % 10 end
end

n = gets.to_i
nums = Hash.new(0)
(1..n).each do |i|
	61.times do
		r = rev i
		if i == r
			nums[i] += 1
			break
		end
		i += r
	end
end
max_val = nums.values.max
max_key = nums.select{|k, v| v == max_val}.keys.first
puts max_key.to_s + " " + max_val.to_s