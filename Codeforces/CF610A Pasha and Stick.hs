main :: IO()
main = print . solve . read =<< getLine

solve :: Int -> Int
solve n | odd n = 0
        | otherwise = n `div` 4 - if n `mod` 4 == 0 then 1 else 0
