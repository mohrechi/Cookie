main :: IO()
main = print . solve 1 . map read . words =<< getLine

solve :: Int -> [Int] -> Int
solve i [k, r] = let m = i * k `mod` 10
                 in if m == r || m == 0
                    then i
                    else solve (i + 1) [k, r]
