main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Integer] -> Integer
solve (n:m:a) = solve' a 1
    where
        solve' :: [Integer] -> Integer -> Integer
        solve' []     _    = 0
        solve' (a:ax) last | a >= last = a - last + (solve' ax a)
                           | otherwise = a - last + n + (solve' ax a)
