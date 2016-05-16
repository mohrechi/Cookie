main :: IO()
main = print . solve . map read . words =<< getContents

natureSum :: Int -> Int
natureSum n | odd n = n * div (n + 2) 2
            | otherwise = div n 2 * (n + 1)

findBottom :: Int -> Int -> Int -> Int -> Int
findBottom l r k b | l > r = b
                   | otherwise = let mid = div (l + r) 2
                                     m = natureSum mid
                                 in if m <= k
                                    then findBottom (mid + 1) r k (max b m)
                                    else findBottom l (mid - 1) k b

solve :: [Int] -> Int
solve (n:k:id) = let m = findBottom 1 (min n 63246) (k - 1) 0
                 in id !! (k - m - 1)
