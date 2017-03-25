main :: IO ()
main = print . solve . map read . words =<< getLine

solve :: [Integer] -> Int
solve [a, b] | a > b = 0
             | otherwise = 1 + solve [a * 3, b * 2]
