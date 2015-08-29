import Data.List

main :: IO()
main = print . solve . tail . map read . words =<<getContents

solve :: [Integer] -> Integer
solve a = sum (zipWith (*) [1..] (sort a)) - (maximum a) + (sum a)
