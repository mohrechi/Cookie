import Data.List

main :: IO()
main = output . solve . map read . words =<< getContents

transform :: [Int] -> [Int]
transform [] = []
transform (x:s) = let (ys, zs) = splitAt x s in ys ++ transform zs

solve :: [Int] -> Bool
solve (_:m:x) = length (nub $ transform x) == m

output :: Bool -> IO()
output b = putStrLn $ if b then "YES" else "NO"
