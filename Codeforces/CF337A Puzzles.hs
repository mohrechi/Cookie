import Data.List

main :: IO()
main = print . solve . map (map read . words) . lines =<< getContents

solve :: [[Int]] -> Int
solve input = 
    let n = head $ head input
        f = sort $ head $ tail input
    in solve' f (drop (n - 1) f)
    where
        solve' :: [Int] -> [Int] -> Int
        solve' _ [] = 0x7fffffff
        solve' (x:xs) (y:ys) = min (y - x) (solve' xs ys)
