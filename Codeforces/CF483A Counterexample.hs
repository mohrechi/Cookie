main :: IO()
main = output . solve . map read . words =<< getLine

solve :: [Integer] -> (Integer, Integer, Integer)
solve [l, r] | (mod l 2) == 1 = solve [l + 1, r]
             | l + 2 > r     = (-1, -1, -1)
             | otherwise      = (l, l + 1, l + 2)

output :: (Integer, Integer, Integer) -> IO()
output (a, b, c) | a == -1   = putStrLn "-1"
                 | otherwise = putStrLn $ (show a) ++ " " ++ (show b) ++ " " ++ (show c)
