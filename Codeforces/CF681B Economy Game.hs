main :: IO()
main = output . solve1 . read =<< getLine

output :: Bool -> IO()
output True = putStrLn "YES"
output False = putStrLn "NO"

solve1 :: Int -> Bool
solve1 n | n < 1234567 = solve2 n
         | otherwise = solve2 n || solve1 (n - 1234567)

solve2 :: Int -> Bool
solve2 n | n < 123456 = solve3 n
         | otherwise = solve3 n || solve2 (n - 123456)

solve3 :: Int -> Bool
solve3 n = n `mod` 1234 == 0
