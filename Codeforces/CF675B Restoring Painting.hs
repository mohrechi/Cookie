main :: IO()
main = print . solve . map read . words =<< getLine

solve :: [Integer] -> Integer
solve [n, a, b, c, d] = n * (iter 1)
    where iter :: Integer -> Integer
          iter i | i > n = 0
                 | otherwise = valid i + iter (i + 1)
          valid :: Integer -> Integer
          valid x1 = let sum = a + b + x1
                         x2 = sum - a - c
                         x3 = sum - b - d
                         x4 = sum - c - d
                     in if 1 <= x2 && x2 <= n &&
                           1 <= x3 && x3 <= n &&
                           1 <= x4 && x4 <= n
                        then 1 else 0
