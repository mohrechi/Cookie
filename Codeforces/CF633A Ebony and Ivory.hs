main :: IO()
main = output . solve . map read . words =<< getLine

solve :: [Int] -> Bool
solve [a, b, c] = solve' 0
    where solve' :: Int -> Bool
          solve' x | x > c = False
                   | x == c = True
                   | (c - x) `mod` b == 0 = True
                   | otherwise = solve' (x + a)

output :: Bool -> IO()
output True = putStrLn "Yes"
output False = putStrLn "No"
