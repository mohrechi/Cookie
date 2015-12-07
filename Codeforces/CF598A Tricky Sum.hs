main :: IO()
main = mapM_ (print . solve) . map read . tail . words =<< getContents

solve :: Integer -> Integer
solve n = (div (n * (n + 1)) 2) - (pow2sum 1 n) * 2

pow2sum :: Integer -> Integer -> Integer
pow2sum p n | p > n = 0
            | otherwise = p + (pow2sum (p * 2) n)
