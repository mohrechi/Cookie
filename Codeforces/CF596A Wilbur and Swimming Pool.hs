import Data.List

main :: IO()
main = print . solve . map read . tail . words =<< getContents

solve :: [Int] -> Int
solve a = let x = sort . nub . map snd . filter (even . fst) $ zip [0..] a 
              y = sort . nub . map snd . filter (odd  . fst) $ zip [0..] a 
          in  if (length x) /= 2 || (length y) /= 2 then -1 else ((x !! 1) - (head x)) * ((y !! 1) - (head y))
