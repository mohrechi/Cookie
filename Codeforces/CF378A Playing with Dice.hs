main :: IO()
main = putStrLn . unwords . map show . solve . map read . words =<< getLine

solve :: [Int] -> [Int]
solve [a, b] = solve' a b 1 [0, 0, 0]
    where solve' :: Int -> Int -> Int -> [Int] -> [Int]
          solve' _ _ 7 c = c
          solve' a b i [x, y, z] | abs (a - i) < abs(b - i) = solve' a b (i + 1) [x + 1, y, z]
                                 | abs (a - i) == abs(b - i) = solve' a b (i + 1) [x, y + 1, z]
                                 | abs (a - i) > abs(b - i) = solve' a b (i + 1) [x, y, z + 1]

