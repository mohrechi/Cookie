main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (p:_:x) = solve' [] 1 x
    where solve' :: [Int] -> Int -> [Int] -> Int
          solve' _ _ []     = -1
          solve' h i (x:xs) | elem (mod x p) h = i
                            | otherwise = solve' ((mod x p):h) (i + 1) xs
