import Data.List

main :: IO()
main = print . solve . map read . tail . words =<< getContents

solve :: [Int] -> Int
solve a = solve' (sort a) [] []

solve' :: [Int] -> [Int] -> [Int] -> Int
solve' [] [] [] = 0
solve' [] curr next = (length curr) - 1 + solve' (reverse next) [] []
solve' (a:ax) [] [] = solve' ax [a] []
solve' (a:ax) (c:cx) next | a == c = solve' ax (c:cx) (a:next)
                          | otherwise = solve' ax (a:c:cx) next
