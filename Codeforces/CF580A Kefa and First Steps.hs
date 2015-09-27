main :: IO()
main = print . solve . tail . map read . words =<< getContents

solve :: [Int] -> Int
solve a = solve' a 0 0

solve' :: [Int] -> Int -> Int -> Int
solve' []     _ c = c
solve' (a:ax) l c | a >= l    = solve' ax a (c + 1)
                  | otherwise = max c (solve' ax a 1)
