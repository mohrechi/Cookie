main :: IO()
main = print . solve 0 0 . map read . tail . words =<< getContents

solve :: Int -> Int -> [Int] -> Int
solve _ _ []    = 0
solve i _ (0:x) = solve i 0 x
solve _ 1 (1:x) = 1 + solve 1 1 x
solve i 0 (1:x) = i + 1 + solve 1 1 x
