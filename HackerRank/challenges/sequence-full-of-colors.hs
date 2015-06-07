main :: IO()
main = getContents >>= mapM_ (putStrLn . solve) . tail . lines

solve :: String -> String
solve s | (cond s 'R' 'G') && (cond s 'Y' 'B') = "True"
        | otherwise = "False"

cond :: String -> Char -> Char -> Bool
cond s x y = cond' s 0 0
    where
        cond' :: String -> Int -> Int -> Bool
        cond' ""     a b = a == b
        cond' (s:ss) a b | s == x    = ((abs (a + 1 - b)) <= 1) && (cond' ss (a + 1) b)
                         | s == y    = ((abs (a - 1 - b)) <= 1) && (cond' ss a (b + 1))
                         | otherwise = cond' ss a b
