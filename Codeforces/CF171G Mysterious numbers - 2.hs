main :: IO ()
main = print . solve . map read . words =<< getLine

solve :: [Integer] -> Integer
solve [a, b, 1] = b
solve [a, b, i] = solve [b, a + b, i - 1]
