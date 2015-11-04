main :: IO()
main = putStrLn . solve . map read . words =<< getLine

solve :: [Integer] -> String
solve [0, _] = ""
solve [_, 0] = ""
solve [x, y] | gcd x y /= 1 = "Impossible"
             | x > y        = (show (div (x - 1) y)) ++ "A" ++ (solve [(mod x y), y])
             | otherwise    = (show (div (y - 1) x)) ++ "B" ++ (solve [x, (mod y x)])
