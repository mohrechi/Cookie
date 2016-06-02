import Data.Functor

main :: IO()
main = do
    let readInts = map read . words
    [n, h, k] <- readInts <$> getLine
    a <- readInts <$> getLine
    print $ solve h k a 0

solve :: Integer -> Integer -> [Integer] -> Integer -> Integer
solve _ k []    m = (m + k - 1) `div` k
solve h k (a:s) m | m + a <= h = solve h k s (m + a)
                  | otherwise = let x = (a + m - h + k - 1) `div` k
                                in x + solve h k (a:s) (max 0 (m - k * x))
