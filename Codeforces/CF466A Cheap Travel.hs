main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (n:m:a:b:_) = solve' 0
    where solve' :: Int -> Int
          solve' i | i * m >= n = i * b
                   | otherwise  = min (i * b + (n - i * m) * a) (solve' (i + 1))
