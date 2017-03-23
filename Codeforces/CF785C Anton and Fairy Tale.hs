main :: IO ()
main = print . solve . map read . words =<< getLine

solve :: [Integer] -> Integer
solve [n, m] = min n (m + solve' 0 n n)
               where solve' :: Integer -> Integer -> Integer -> Integer
                     solve' l r d | l > r = d
                                  | otherwise = let mid = (l + r) `div` 2
                                                    cost = mid * (mid - 1) `div` 2
                                                in  if n - cost <= m + mid
                                                    then solve' l (mid - 1) (min d mid)
                                                    else solve' (mid + 1) r d
