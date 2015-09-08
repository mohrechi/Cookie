import Data.List

main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Integer] -> Integer
solve (n:x:c) = solve' (sort c) x
    where
        solve' :: [Integer] -> Integer -> Integer
        solve' []     _ = 0
        solve' (c:cs) x = x * c + (solve' cs (max 1 (x - 1)))
