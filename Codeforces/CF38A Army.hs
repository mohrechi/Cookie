main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (n:d) = let a = d !! (n - 1)
                  b = d !! n
              in solve' 1 a b d
              where solve' :: Int -> Int -> Int -> [Int] -> Int
                    solve' _ _ _ []    = 0
                    solve' i a b (d:x) | a <= i && i < b = d + solve' (i + 1) a b x
                                       | otherwise       = solve' (i + 1) a b x
