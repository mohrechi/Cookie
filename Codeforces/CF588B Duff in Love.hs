main :: IO()
main = print . solve 1 2 . read =<< getLine

solve :: Integer -> Integer -> Integer -> Integer
solve l d n | mod n d == 0 = let next = solve d d (div n d)
                             in if d == l then next else d * next
            | d * d > n    = n
            | otherwise    = solve l (d + 1) n
