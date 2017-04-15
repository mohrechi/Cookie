main :: IO ()
main = print . ([0, 2, 3, 1, 2, 1] !!) . read =<< getLine
