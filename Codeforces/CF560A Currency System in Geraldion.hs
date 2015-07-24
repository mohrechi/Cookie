main :: IO()
main = print . solve . tail . map read . words =<< getContents

solve :: [Int] -> Int
solve []    = 1
solve (a:s) = if a == 1 then -1 else (solve s)
