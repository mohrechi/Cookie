main :: IO()
main = print . solve . map read . tail . words =<< getContents

solve :: [Int] -> Int
solve (m:a) = solve' a
    where solve' :: [Int] -> Int
          solve' [] = -1
          solve' (x:y:s) | m > x && y == 0 = max 0 (solve' s)
                         | m > x = max (100 - y) (solve' s)
                         | m == x && y == 0 = max 0 (solve' s)
                         | otherwise = solve' s
