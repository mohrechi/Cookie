main :: IO()
main = print . solve . map read . words =<< getLine

solve :: [Int] -> Int
solve [n, k] = n + k - n `mod` k
