main :: IO ()
main = print . solve "" =<< getLine

solve :: String -> String -> Int
solve pre [] = solve' pre
solve pre (s:sx) = maximum [solve' (pre ++ "V" ++ sx), solve' (pre ++ "K" ++ sx), solve (pre ++ [s]) sx]

solve' :: String -> Int
solve' [] = 0
solve' ('V':'K':sx) = 1 + solve' sx
solve' (s:sx) = solve' sx
