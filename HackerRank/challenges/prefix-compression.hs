main :: IO()
main = getContents >>= putStrLn . solve . lines

solve :: [String] -> String
solve (p:q:s) = 
    let l = prefixLen p q
        pre = take l p
        ps = drop l p
        qs = drop l q
        pl = length ps
        ql = length qs
    in (show l) ++ " " ++ pre ++ "\n" ++ (show pl) ++ " " ++ ps ++ "\n" ++ (show ql) ++ " " ++ qs ++ "\n"
    where
        prefixLen :: String -> String -> Int
        prefixLen [] _ = 0
        prefixLen _ [] = 0
        prefixLen (p:ps) (q:qs) | p == q = 1 + prefixLen ps qs
                                | otherwise = 0