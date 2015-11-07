main :: IO()
main = print . solve . map read . drop 2 . words =<< getContents

solve :: [Int] -> Int
solve [] = 0
solve (a:b:x) = let rest = solve x
                in if a == 0 && b == 0 then rest else 1 + rest
