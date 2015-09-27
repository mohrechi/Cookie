import Data.Function
import Data.List

main :: IO()
main = output . solve . input . tail . map read . words =<< getContents

input :: [Int] -> [(Int, Int)]
input []      = []
input (a:b:s) = (a, b):(input s)

solve :: [(Int, Int)] -> Bool
solve p = solve' (sortBy (on compare fst) p)
    where
        solve' :: [(Int, Int)] -> Bool
        solve' []                = False
        solve' [(_, _)]          = False
        solve' ((_, b):(c, d):x) | b > d     = True
                                 | otherwise = solve' ((c, d):x)

output :: Bool -> IO()
output b = putStrLn $ if b then "Happy Alex" else "Poor Alex"
