main = do
    line <- getLine
    let x = read line
    print $ div (x + 4) 5
