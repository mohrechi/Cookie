main :: IO ()
main = print . solve 0 . map read . words =<< getContents

solve :: Int -> [Int] -> Int
solve 200 _ = -1
solve i [a, b, c, d] | b == d    = b
                     | b < d     = solve (i + 1) [a, b + a, c, d]
                     | otherwise = solve (i + 1) [a, b, c, d + c]
