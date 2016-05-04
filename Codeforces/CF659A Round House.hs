main :: IO()
main = print . solve . map read . words =<< getLine

solve :: [Int] -> Int
solve [n, a, b] = 1 + mod (a - 1 + b + n * 100) n
