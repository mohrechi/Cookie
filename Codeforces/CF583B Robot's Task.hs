main :: IO()
main = print . solve 0 0 [] . map read . tail . words =<< getContents

solve :: Int -> Int -> [Int] -> [Int] -> Int
solve a c [] [] = a
solve a c r [] = solve (a + 1) c [] r
solve a c r (v:x) | c >= v = solve a (c + 1) r x
                  | otherwise = solve a c (v:r) x
