import Data.List

main :: IO()
main = print . solve . tail . map read . words =<< getContents

solve :: [Integer] -> Integer
solve a = 
    let sa = sort a
    in  count (compress (tail sa) (head sa) 1) 0 0 0

compress :: [Integer] -> Integer -> Integer -> [(Integer, Integer)]
compress []     num cnt = [(num, cnt)]
compress (a:ax) num cnt | num == a  = compress ax num (cnt + 1)
                        | otherwise = (num, cnt):(compress ax a 1)
                        
count :: [(Integer, Integer)] -> Integer -> Integer -> Integer -> Integer
count []             _    n y = max n y
count ((num, cnt):s) last n y | num == last + 1 = count s num (max n y) (n + num * cnt)
                              | otherwise       = count s num (max n y) ((max n y) + num * cnt)
