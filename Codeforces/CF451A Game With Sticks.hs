main :: IO()
main = getLine >>=
    putStrLn . solve . map read . words
    
solve :: [Int] -> String
solve [a, b] = if even (min a b) then "Malvika" else "Akshat"