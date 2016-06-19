import Data.List

main :: IO()
main = print . solve . map read . words =<< getLine

cnt :: Integer -> Integer -> Integer
cnt n k = (n + (5 - k) `mod` 5) `div` 5

solve :: [Integer] -> Integer
solve [n, m] = solve' 0
    where solve' :: Integer -> Integer
          solve' 5 = 0
          solve' k = (cnt n k) * (cnt m ((5 - k) `mod` 5)) + solve' (k + 1)
