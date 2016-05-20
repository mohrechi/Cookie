import Data.List

main :: IO()
main = print . solve . map read . tail . words =<< getContents

solve :: [Int] -> Int
solve a = maximum a * 2 - sum a + 1
