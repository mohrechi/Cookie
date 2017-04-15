main :: IO ()
main = do
    s <- getLine
    let i = read s
    putStrLn ["01001010111001010" !! i]
