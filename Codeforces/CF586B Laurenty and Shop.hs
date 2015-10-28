import Data.List

main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve a = let n = head a
              r1 = drop 1 a
              a1 = take (n - 1) r1
              r2 = drop (n - 1) r1
              a2 = take (n - 1) r2
              b = drop (n - 1) r2
          in solve' n a1 a2 b

solve' :: Int -> [Int] -> [Int] -> [Int] -> Int
solve' n a1 a2 b = let p = sort $ map (dist a1 a2 b) [0..(n-1)]
                   in (head p) + (p !! 1)

dist :: [Int] -> [Int] -> [Int] -> Int -> Int
dist a1 a2 b i = (sum (take i a1)) + (sum (drop i a2)) + (b !! i)
