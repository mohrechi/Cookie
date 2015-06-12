main :: IO()
main = print . solve . read =<< getLine

solve :: Int -> Int
solve n = solve' n 1 2
    where
        solve' :: Int -> Int -> Int -> Int
        solve' n s i | n < s = 0
                     | otherwise = 1 + (solve' (n - s) (s + i) (i + 1))