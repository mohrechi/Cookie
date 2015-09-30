main :: IO()
main = print . solve . map read . lines =<< getContents

solve :: [Int] -> Int
solve (x:n:xs) = solve' 0 1
    where
        solve' :: Int -> Int -> Int
        solve' s i | s > x = 0
                   | s == x = 1
                   | i ^ n > x = 0
                   | otherwise = (solve' (s + i ^ n) (i + 1)) + (solve' s (i + 1))