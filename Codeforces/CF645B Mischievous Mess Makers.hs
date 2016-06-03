main :: IO()
main = print . solve . map read . words =<< getLine

solve :: [Integer] -> Integer
solve [n, k] = let m = max (n - 2 * k) 0
               in n * (n - 1) `div` 2 - m * (m - 1) `div` 2
