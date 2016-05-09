main :: IO()
main = print . solve 0 . map read . tail . words =<< getContents

solve :: Int -> [Int] -> Int
solve c [] = min (c + 15) 90
solve c (x:s) | c + 15 >= 90 = 90
              | x - c > 15 = c + 15
              | otherwise = solve x s
