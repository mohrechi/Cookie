import Data.List

main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Double
solve (n:l:a) =
    let sa = sort a
    in (fromIntegral (max ((head sa) * 2) (solve' sa))) * 0.5
    where
        solve' :: [Int] -> Int
        solve' [a] = (l - a) * 2
        solve' (a:b:x) = max (b - a) (solve' (b:x))
