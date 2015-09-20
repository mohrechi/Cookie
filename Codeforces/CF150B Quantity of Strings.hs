cmod = 10^9 + 7

main :: IO()
main = print . solve . map read . words =<< getLine

solve :: [Integer] -> Integer
solve [n, m, k] | k == 1 || k > n = mod (m^n) cmod
                | n == k          = mod (m^(div (n+1) 2)) cmod
                | odd k           = mod (m*m) cmod
                | otherwise       = m
