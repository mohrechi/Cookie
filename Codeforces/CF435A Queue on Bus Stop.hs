main :: IO()
main = print . solve . map read . tail . words =<< getContents

solve :: [Int] -> Int
solve (m:a) = solve' m a
    where solve' :: Int -> [Int] -> Int
          solve' _ [] = 0
          solve' i (a:x) | a+i > m = 1 + solve' 0 (a:x)
                         | otherwise = solve' (a+i) x
