main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve [a, b] | a > b = solve [b, a]
             | a < 0 = -1
             | a == 0 = 0
             | otherwise = 1 + solve [a + 1, b - 2]
