main :: IO ()
main = putStrLn . solve . read =<< getLine

solve :: Int -> String
solve 0 = ""
solve n | n `div` 2 `mod` 2 == 0 = 'a' : solve (n - 1)
        | otherwise = 'b' : solve (n - 1)
