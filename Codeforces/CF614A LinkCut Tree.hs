main :: IO()
main = putStrLn . unwords . map show . proof . solve . map read . words =<< getLine

proof :: [Integer] -> [Integer]
proof [] = [-1]
proof x = x

solve :: [Integer] -> [Integer]
solve [l, r, k] = solve' 1
    where solve' :: Integer -> [Integer]
          solve' x | x < l = solve' (x * k)
                   | x > r = []
                   | otherwise = x : solve' (x * k)
