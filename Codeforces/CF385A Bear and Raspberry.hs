main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (_:c:x) = solve' x
    where
        solve' :: [Int] -> Int
        solve' [_]     = 0
        solve' (a:b:x) = max (a - b - c) (solve' (b:x)) 
