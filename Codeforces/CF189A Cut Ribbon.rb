n, a, b, c = gets.split.map &:to_i
dp = Array.new n + 1, 0
dp[0] = 1
(1..n).each do |i|
    dp[i] = [dp[i], dp[i - a] + 1].max if i >= a && dp[i - a] > 0
    dp[i] = [dp[i], dp[i - b] + 1].max if i >= b && dp[i - b] > 0
    dp[i] = [dp[i], dp[i - c] + 1].max if i >= c && dp[i - c] > 0
end
puts dp[n] - 1
