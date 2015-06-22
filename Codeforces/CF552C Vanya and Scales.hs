main :: IO()
main = putStrLn . solve . map read . words =<< getLine

solve :: [Int] -> String
solve (n:m:_) | solve' m = "YES"
              | otherwise  = "NO"
    where
        solve' :: Int -> Bool
        solve' 0 = True
        solve' m | elem (rem m n) [0, 1] = solve' (div m n)
                 | (rem m n) == (n - 1)  = solve' ((div m n) + 1)
                 | otherwise             = False