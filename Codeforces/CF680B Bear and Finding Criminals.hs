import Data.List
import Data.Functor

main :: IO()
main = do
    [n, a] <- map read . words <$> getLine
    t <- map read . words <$> getLine
    print $ solve n a t

solve :: Int -> Int -> [Int] -> Int
solve n a t = let (x, y) = splitAt a t
                  rx = reverse x
                  h = head rx
                  r = solve' (tail rx) y
              in r + h
              where solve' :: [Int] -> [Int] -> Int
                    solve' []     []     = 0
                    solve' (x:xs) []     = x + solve' xs []
                    solve' []     (y:ys) = y + solve' [] ys
                    solve' (x:xs) (y:ys) = solve' xs ys + if x + y == 2 then 2 else 0
