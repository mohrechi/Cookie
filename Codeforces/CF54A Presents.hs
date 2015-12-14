main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (n:k:c:a) = solve' 0 0 a
    where solve' :: Int -> Int -> [Int] -> Int
          solve' ni ki a | ni > n = 0
                         | ki == k && ((length a) > 0 && ni == (head a)) = 1 + solve' (ni + 1) 1 (tail a)
                         | ki == k = 1 + solve' (ni + 1) 1 a
                         | ((length a) > 0 && ni == (head a)) = 1 + solve' (ni + 1) 1 (tail a)
                         | otherwise = solve' (ni + 1) (ki + 1) a
