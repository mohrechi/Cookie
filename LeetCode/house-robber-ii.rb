def rob(nums)
    n = nums.length
    return 0 if n == 0
    return nums[0] if n == 1
    dp = Array.new n, nil
    n.times do |i|
        dp[i] = Array.new 2, 0
    end
    dp[0][0] = 0
    dp[0][1] = nums[0]
    (1...n).each do |i|
        dp[i][0] = [dp[i - 1][0], dp[i - 1][1]].max
        dp[i][1] = nums[i] + dp[i - 1][0]
    end
    ans = dp[n - 1][0]
    dp[0][0] = 0
    dp[0][1] = 0
    (1...n).each do |i|
        dp[i][0] = [dp[i - 1][0], dp[i - 1][1]].max
        dp[i][1] = nums[i] + dp[i - 1][0]
    end
    return [ans, dp[n - 1][0], dp[n - 1][1]].max
end
