main :: IO()
main = putStrLn . solve =<< getLine

solve :: String -> String
solve s | solve' s False False = "YES"
        | otherwise = "NO"
    where
        solve' :: String -> Bool -> Bool -> Bool
        solve' _ True True = True
        solve' "" a b = a && b
        solve' ('A':'B':'A':ss) a b = (solve' ('A':ss) True b) || (solve' ss a True)
        solve' ('B':'A':'B':ss) a b = (solve' ('B':ss) a True) || (solve' ss True b)
        solve' ('A':'B':ss) a b = solve' ss True b
        solve' ('B':'A':ss) a b = solve' ss a True
        solve' (s:ss) a b = solve' ss a b