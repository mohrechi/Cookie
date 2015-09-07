import Data.List

main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (n:k:f) = 
    let sf = (sortBy (flip compare) f)
    in (solve' sf k) * 2
    where
        solve' :: [Int] -> Int -> Int
        solve' []     _ = 0
        solve' (f:fs) i | i == k    = f - 1 + (solve' fs 1)
                        | otherwise = solve' fs (i + 1)
