main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve [0, m] = 0
solve [n, m] | n < m     = -1
             | otherwise = (div ((div (n + 1) 2) + (m - 1)) m) * m
