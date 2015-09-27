import Data.Char

main :: IO()
main = print . solve . words =<< getContents

solve :: [String] -> Int
solve (s:sk:sw) = let k = read sk
                      w = map read sw
                      i = snd . maximum $ zip w [0..]
                      c = chr (i + (ord 'a'))
                      f = s ++ (concat [[c] | r <- [1..k]])
                  in  solve' f 1 w
                  where
                      solve' :: String -> Int -> [Int] -> Int
                      solve' []     _ _ = 0
                      solve' (f:fs) i w = (w !! ((ord f) - (ord 'a'))) * i + (solve' fs (i + 1) w)
