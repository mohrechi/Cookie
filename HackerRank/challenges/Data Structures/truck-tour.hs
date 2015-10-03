main :: IO()
main = print . solve . map read . tail . words =<< getContents

solve :: [Int] -> Int
solve a = solve' a 0 0 0

solve' :: [Int] -> Int -> Int -> Int -> Int
solve' []      _ _ i = i
solve' (a:b:x) s j i | ns < 0    = solve' x 0  (j + 1) (j + 1)
                     | otherwise = solve' x ns (j + 1) i
                     where ns = s + a - b
