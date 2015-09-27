main :: IO()
main = print . solve . map read . words =<< getLine

solve :: [Int] -> Int
solve [n, x] = sum $ map solve' [1..n]
    where
        solve' :: Int -> Int
        solve' i | (mod x i) == 0 && (div x i) <= n = 1
                 | otherwise = 0
