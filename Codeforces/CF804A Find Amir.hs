main :: IO ()
main = print . solve . read =<< getLine

solve :: Int -> Int
solve n = (n - 1) `div` 2
