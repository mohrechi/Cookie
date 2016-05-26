import Data.List

main :: IO()
main = putStrLn . unwords . map show . solve . map read . words =<< getContents

solve :: [Int] -> [Int]
solve (n:a) = let b = sort a
                  h = div (n + 1) 2
                  (l, r) = splitAt h b
              in solve' l r
              where solve' :: [Int] -> [Int] -> [Int]
                    solve' [] [] = []
                    solve' l [] = l
                    solve' (l:ls) (r:rs) = l : r : solve' ls rs
