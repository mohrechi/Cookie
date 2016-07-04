main :: IO()
main = do
    s <- getLine
    putStr s
    putStrLn $ reverse s
