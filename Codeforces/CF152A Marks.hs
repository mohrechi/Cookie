import Data.List

main :: IO()
main = print . solve . tail . lines =<< getContents

solve :: [String] -> Int
solve s = let s' = transpose s
              ms = map maximum s'
          in  length [x | x <- s, any (uncurry (==)) (zip x ms)]
