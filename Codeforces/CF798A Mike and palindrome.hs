main :: IO ()
main = output . solve =<< getLine

output :: Bool -> IO ()
output True = putStrLn "YES"
output False = putStrLn "NO"

solve :: String -> Bool
solve s = let d = diff s (reverse s)
          in if d == 2
             then True
             else if d == 0
                then odd (length s)
                else False

diff :: String -> String -> Int
diff "" "" = 0
diff (a:ax) (b:bx) | a == b = diff ax bx
                   | otherwise = 1 + diff ax bx
