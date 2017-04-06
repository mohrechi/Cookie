main :: IO ()
main = do
    s <- getLine
    let [sa, sb] = words s
        a = read sa :: Integer
        b = read $ reverse sb :: Integer
    print (a + b)
