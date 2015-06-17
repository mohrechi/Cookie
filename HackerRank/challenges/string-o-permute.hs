main :: IO()
main = getContents >>= mapM_ (putStrLn . solve) . tail . lines

solve :: String -> String
solve [] = []
solve (x:y:xs) = y:x:(solve xs)