main :: IO()
main = print . solve . head . tail . words =<< getContents

solve :: String -> Int
solve s = solve' s [] 0

solve' :: String -> [Char] -> Int -> Int
solve' []     _      num = num
solve' (c:cs) []     0   = solve' cs [c] 1
solve' (c:cs) (s:ss) num | c == s    = solve' cs (c:s:ss) (num+1)
                         | otherwise = solve' cs ss (num-1)
