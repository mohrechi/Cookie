main :: IO()
main = getLine >>=
    print . solve. map read . words
    
solve :: [Int] -> Int
solve [k, n, w] = solve' k w 0
    where
        solve' :: Int -> Int -> Int -> Int
        solve' ki 0 s = max 0 (s - n)
        solve' ki w s = solve' (ki + k) (w - 1) (s + ki)