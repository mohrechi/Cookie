main :: IO ()
main = output . solve =<< getLine

output :: Bool -> IO ()
output True = putStrLn "YES"
output False = putStrLn "NO"

solve :: String -> Bool
solve s = let d = diff s (reverse s)
          in d == 2 || d == 0 && odd (length s)

diff :: String -> String -> Int
diff "" "" = 0
diff (a:ax) (b:bx) | a == b = diff ax bx
                   | otherwise = 1 + diff ax bx
