main :: IO ()
main = putStrLn . solve . words =<< getContents

solve :: [String] -> String
solve [a, b] = if solve' a b then b else "-1"

solve' :: String -> String -> Bool
solve' "" "" = True
solve' (a:ax) (b:bx) | a < b = False
                     | otherwise = solve' ax bx
