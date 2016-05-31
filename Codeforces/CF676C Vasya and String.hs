import Data.List
import Data.Functor

main :: IO()
main = do
    [_, k] <- map read . words <$> getLine
    s <- getLine
    print $ maximum $ map (\x -> solve (== x) s k) "ab"

solve :: (Char -> Bool) -> String -> Int -> Int
solve f s k = solve' s s 0 0
    where solve' :: String -> String -> Int -> Int -> Int
          solve' []     []     _   _   = 0
          solve' []     (t:ts) cnt len | cnt <= k  = len
                                       | f t       = solve' [] ts cnt (len - 1)
                                       | otherwise = solve' [] ts (cnt - 1) (len - 1)
          solve' (h:hs) (t:ts) cnt len | cnt <= k  = max len (solve' hs (t:ts) (cnt + if f h then 0 else 1) (len + 1))
                                       | otherwise = solve' (h:hs) ts (cnt - if f t then 0 else 1) (len - 1)
