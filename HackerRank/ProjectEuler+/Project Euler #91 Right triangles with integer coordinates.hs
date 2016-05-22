main :: IO()
main = print . solve . read =<< getLine

solve :: Integer -> Integer
solve n = 3 * n * n + 2 * sum (map count [(x, y) | x <- [1..n], y <- [1..n]])
    where count :: (Integer, Integer) -> Integer
          count (x, y) = let g = gcd x y
                         in min (div (y * g) x) (div ((n - x) * g) y)
