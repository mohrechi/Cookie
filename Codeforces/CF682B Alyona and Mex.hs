import Data.List

main :: IO()
main = print . solve 1 . sort . map read . tail . words =<< getContents

solve :: Int -> [Int] -> Int
solve i [] = i
solve i (a:s) | i <= a = solve (i + 1) s
              | otherwise = solve i s
