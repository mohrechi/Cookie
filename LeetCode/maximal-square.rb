def maximal_square(matrix)
    row = matrix.length
    return 0 if row == 0
    col = matrix[0].length
    return 0 if col == 0
    dp = Array.new row, nil
    row.times do |i|
        dp[i] = Array.new col, 0
    end
    ans = 0
    row.times do |i|
        col.times do |j|
            dp[i][j] = matrix[i][j].to_i
            if i > 0 and j > 0 and dp[i][j] > 0
                dp[i][j] = [dp[i-1][j], dp[i][j-1], dp[i-1][j-1]].min + 1
            end
            ans = [ans, dp[i][j]].max
        end
    end
    ans * ans
end
