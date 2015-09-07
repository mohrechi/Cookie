import Data.Bits

main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (_:m:k:x) = solve' (init x) (last x)
    where solve' :: [Int] -> Int -> Int
          solve' []     _ = 0
          solve' (x:xs) l | popCount (xor x l) <= k = 1 + solve' xs l
                          | otherwise               = solve' xs l
