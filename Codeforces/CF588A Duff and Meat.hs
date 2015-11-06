main :: IO()
main = print . solve 100 . map read . tail . words =<< getContents

solve :: Int -> [Int] -> Int
solve _ []      = 0
solve m (a:p:x) = let n = min m p
                  in n * a + solve n x
