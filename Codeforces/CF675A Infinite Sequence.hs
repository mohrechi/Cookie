main :: IO()
main = output . solve . map read . words =<< getLine

solve :: [Integer] -> Bool
solve [a, b, c] | c == 0 = a == b
                | c > 0 = b >= a && mod (b - a) c == 0
                | c < 0 = a >= b && mod (a - b) c == 0

output :: Bool -> IO()
output b = putStrLn $ if b then "YES" else "NO"
