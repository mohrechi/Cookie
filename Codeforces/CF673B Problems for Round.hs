main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (n:m:s) = let (a, b) = range s 1 n
                in max 0 (b - a)

range :: [Int] -> Int -> Int -> (Int, Int)
range []      a b = (a, b)
range (x:y:s) a b | x > y = range (y:x:s) a b
                  | otherwise = range s (max a x) (min b y)
