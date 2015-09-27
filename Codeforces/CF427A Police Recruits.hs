main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (n:a) = solve' a 0

solve' :: [Int] -> Int -> Int
solve' []     sum | sum < 0   = abs sum
                  | otherwise = 0
solve' (a:ax) sum | sum < 0   = max (abs sum) (solve' ax (sum + a))
                  | otherwise = solve' ax (sum + a)
