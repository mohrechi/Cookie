main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (n:m:k:a) = solve' m k a

solve' :: Int -> Int -> [Int] -> Int
solve' _ _ []    = 0
solve' 0 m (1:x) = 1 + solve' 0 m x
solve' n m (1:x) = solve' (n - 1) m x
solve' 0 0 (2:x) = 1 + solve' 0 0 x
solve' n 0 (2:x) = solve' (n - 1) 0 x
solve' n m (2:x) = solve' n (m - 1) x
