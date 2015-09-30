solve :: String -> String
solve s = solve' s []
    where
        solve' :: String -> [Char] -> String
        solve' "" v = ""
        solve' (s:ss) v = 
            if exist v s then 
                solve' ss v 
            else 
                [s] ++ solve' ss (s:v)
            where
                exist :: [Char] -> Char -> Bool
                exist [] c = False
                exist (x:xs) c = if x == c then True else exist xs c

main = do
    s <- getLine
    putStrLn(solve s)