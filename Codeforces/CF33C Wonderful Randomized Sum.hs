import Data.List

main :: IO()
main = print . solve . map read . tail . words =<< getContents

solve :: [Int] -> Int
solve a = let pre = calcMaxSum a
              suf = reverse $ calcMaxSum (reverse a)
          in solve' pre (tail suf) (sum a)
          where solve' :: [Int] -> [Int] -> Int -> Int
                solve' [a]    []     m = max a m
                solve' (a:ax) (b:bx) m = solve' ax bx (max m (a + b))

accumulate :: (a -> b -> a) -> a -> [b] -> [a]
accumulate _  _    []    = []
accumulate op last (a:s) = let v = op last a
                           in v : accumulate op v s

transition :: (Int, Int) -> Int -> (Int, Int)
transition (a, b) c = (a - c, max (c + max a b) (a - c))

calcMaxSum :: [Int] -> [Int]
calcMaxSum = map snd . accumulate transition (0, 0)
