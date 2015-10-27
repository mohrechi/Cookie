main :: IO()
main = print . solve True False 0 . map read . tail . words =<< getContents

solve :: Bool -> Bool -> Int -> [Int] -> Int
solve _     False cnt []    = cnt
solve False True  cnt []    = cnt - 1
solve _     _     cnt (1:x) = solve False False (cnt + 1) x
solve True  False cnt (0:x) = solve True  False cnt       x
solve False True  cnt (0:x) = solve True  False (cnt - 1) x
solve False False cnt (0:x) = solve False True  (cnt + 1) x
