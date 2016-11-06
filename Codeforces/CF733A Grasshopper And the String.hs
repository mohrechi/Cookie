main :: IO()
main = print . solve 1 =<< getLine

vowels :: String
vowels = "AEIOUY"

solve :: Int -> String -> Int
solve last []    = last
solve last (c:s) | elem c vowels = max last (solve 1 s)
                 | otherwise = solve (last + 1) s
