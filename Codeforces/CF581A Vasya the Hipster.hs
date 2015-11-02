main :: IO()
main = putStrLn . solve . map read . words =<< getLine

solve :: [Int] -> String
solve [a, b] = (show (min a b)) ++ " " ++ (show (div ((max a b) - (min a b)) 2))
