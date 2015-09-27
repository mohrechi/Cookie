import Data.List

main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (n:d:t) =
    let minTime = (sum t) + (n - 1) * 10
    in  if minTime > d then -1 else (n - 1) * 2 + (div (d - minTime) 5)
