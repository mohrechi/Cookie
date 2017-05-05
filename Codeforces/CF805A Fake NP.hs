main :: IO ()
main = print . solve . map read . words =<< getLine

solve :: [Int] -> Int
solve [a, b] | a == b = a
             | otherwise = 2
