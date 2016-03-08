main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Integer] -> Integer
solve [n, a, b, c] = let m = max 0 (div (n - c) (b - c))
                     in  max (div n a) (m + (div (n - m * (b - c)) a))
