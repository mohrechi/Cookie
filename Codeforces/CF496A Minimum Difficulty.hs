main :: IO()
main = print . solve . tail . map read . words =<< getContents

solve :: [Int] -> Int
solve a = max (solveDiff a) (solveRemove a)

solveDiff :: [Int] -> Int
solveDiff [a, b]  = b - a
solveDiff (a:b:s) = max (b - a) (solveDiff (b:s))

solveRemove :: [Int] -> Int
solveRemove [a, b, c] = c - a
solveRemove (a:b:c:s) = min (c - a) (solveRemove (b:c:s))
