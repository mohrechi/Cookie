main :: IO()
main = getContents >>= putStrLn . solve . map (map read . words) . lines

solve :: [[Int]] -> String
solve input = 
    let n = head $ head input
        x = head $ tail input
    in solve' x n []
    where 
        solve' :: [Int] -> Int -> [Int] -> String
        solve' [] _ _ = "YES"
        solve' (x:xs) n y | elem x y = "NO"
                          | x < 1 || x > n = "NO"
                          | otherwise = solve' xs n (x:y)