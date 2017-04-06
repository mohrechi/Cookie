main :: IO ()
main = do
    s <- getLine
    let a = read s
    print (6 * a * (a - 1) + 1)
