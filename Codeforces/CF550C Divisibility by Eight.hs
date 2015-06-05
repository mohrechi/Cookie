main :: IO()
main = putStrLn . solve =<< getLine

solve :: String -> String
solve s = 
    let sub = search 0
    in if null sub then "NO" else "YES\n" ++ sub
    where 
        search :: Int -> String
        search 1000 = ""
        search    x | isSub s (show x) = (show x)
                    |        otherwise = search (x + 8)
                    
        isSub :: String -> String -> Bool
        isSub      _     "" = True
        isSub     ""      _ = False
        isSub (s:ss) (t:ts) |    s == t = isSub ss ts
                            | otherwise = isSub ss (t:ts)
        