main :: IO()
main = getLine >>= print . solve . read

solve n | odd n = (solve (n - 1)) - n
        | otherwise = div n 2