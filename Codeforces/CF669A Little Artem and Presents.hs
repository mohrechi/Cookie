main :: IO()
main = print . solve . read =<< getLine

solve :: Int -> Int
solve n = 2 * div n 3 + if mod n 3 > 0 then 1 else 0
