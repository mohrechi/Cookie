main :: IO()
main = getLine >>= putStrLn . solve

solve :: String -> String
solve s = solve' s []
    where
        solve' :: String -> [Char] -> String
        solve' "" _ = ""
        solve' (s:ss) v | elem s v  = solve' ss v 
                        | otherwise = s:(solve' ss (s:v))