main :: IO()
main = print . solve 0 . map read . tail . words =<< getContents

solve :: Integer -> [Integer] -> Integer
solve _ []    = 0
solve l (a:x) = (abs (a - l)) + (solve a x)
