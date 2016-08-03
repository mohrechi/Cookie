main :: IO()
main = putStrLn . unwords . map show . solve 1 . map read . words =<< getContents

solve :: Int -> [Int] -> [Int]
solve i (n:p) | null p = [-1]
              | otherwise = let ([a, b, c, d], ps) = splitAt 4 p
                                m1 = min a b
                                m2 = min c d
                            in if m1 + m2 <= n
                               then [i, m1, n - m1]
                               else solve (i + 1) (n:ps)
