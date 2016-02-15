n, _ = gets.split.map &:to_i
prices = Array.new n
n.times do |i|
    prices[i] = gets.split.map(&:to_i).min
end
puts prices.max
