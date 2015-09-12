main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (n:m:a) = solve' a 1 1
    where
        solve' :: [Int] -> Int -> Int -> Int
        solve' []     _ _ = 4
        solve' (1:ax) i j | i == 1 || i == n = 2
                          | j == 1 || j == m = 2
        solve' (_:ax) i j | j == m           = solve' ax (i + 1) 1
                          | otherwise        = solve' ax i (j + 1)
