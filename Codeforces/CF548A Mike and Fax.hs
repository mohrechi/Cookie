main :: IO()
main = getContents >>= putStrLn . solve . lines

solve :: [String] -> String
solve [s, sk] = 
    let len = length s
        k   = read sk
        m   = div len k
    in if (mod len k) == 0 && (solve' s m m "") then "YES" else "NO"
        where
            solve' :: String -> Int -> Int -> String -> Bool
            solve' "" m 0 sub = palin sub
            solve' (x:xs) m 0 sub = (palin sub) && (solve' xs m (m-1) [x])
            solve' (x:xs) m i sub = solve' xs m (i-1) (x:sub)
            
            palin :: String -> Bool
            palin s = s == (reverse s)
            