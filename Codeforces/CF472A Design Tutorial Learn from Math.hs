main = do
    input <- getLine
    let n = read input
    if odd n then
        putStrLn $ ("9 " ++ (show $ n - 9))
    else
        putStrLn $ ("4 " ++ (show $ n - 4))