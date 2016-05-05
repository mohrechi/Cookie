import Data.List

main :: IO()
main = print . solve . map read . words =<< getLine

solve :: [Int] -> Int
solve [a, b, c] = minimum [a + a + b + b, a + c + b, a + c + c + a, b + c + c + b]
