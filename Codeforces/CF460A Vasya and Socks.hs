solve :: [Int] -> Int
solve [n, m] = solve' 1 n
    where
        solve' :: Int -> Int -> Int
        solve' d 0 = 0
        solve' d n | (mod d m) == 0 = 1 + solve' 1 n
                   | otherwise = 1 + solve' (d + 1) (n - 1)

main :: IO()
main = getLine >>=
    print . solve . map read . words