main :: IO()
main = getLine >>= putStrLn . solve

solve :: String -> String
solve s = solve' s ' ' 0
    where
        solve' :: String -> Char -> Int -> String
        solve' [] last 0 = ""
        solve' [] last 1 = [last]
        solve' [] last cnt = last:(show cnt)
        solve' (x:xs) last cnt | x == last = solve' xs x (cnt + 1)
                               | otherwise = (solve' [] last cnt) ++ (solve' xs x 1)