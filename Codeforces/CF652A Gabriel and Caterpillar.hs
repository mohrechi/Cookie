import Data.Functor

main :: IO()
main = do
    [h1, h2] <- map read . words <$> getLine
    [a, b] <- map read . words <$> getLine
    print $ solve h1 h2 a b

solve :: Int -> Int -> Int -> Int -> Int
solve h1 h2 a b | h1 + 8 * a >= h2 = 0
                | a <= b = -1
                | otherwise = let x = h2 - h1 - 8 * a
                                  y = 12 * (a - b)
                              in div (x + y - 1) y
