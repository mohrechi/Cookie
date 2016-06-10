import Data.List

main :: IO()
main = print . solve . map read . words =<< getLine

solve :: [Int] -> Int
solve a = sum a - maximum (map (solve' a []) [2, 3])
    where solve' :: [Int] -> [Int] -> Int -> Int
          solve' [] t n | length t == n = if length (group t) == 1
                                         then n * head t
                                         else 0
                        | otherwise = 0
          solve' (a:s) t n = max (solve' s t n) (solve' s (a:t) n)
