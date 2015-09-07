import Data.List

main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (n:s) = 
    let a = take n s
        b = drop (n + 1) s
    in  solve' (sort a) (sort b)
    where
        solve' :: [Int] -> [Int] -> Int
        solve' [] _ = 0
        solve' _ [] = 0
        solve' (a:ax) (b:bx) | abs (a - b) <= 1 = 1 + (solve' ax bx)
                             | a < b            = solve' ax (b:bx)
                             | otherwise        = solve' (a:ax) bx
