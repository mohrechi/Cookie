main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (n:x:seg) = solve' 0 seg
    where
        solve' :: Int -> [Int] -> Int
        solve' _    []       = 0
        solve' last (l:r:ss) = (mod (l-last-1) x) + (r-l+1) + (solve' r ss)
