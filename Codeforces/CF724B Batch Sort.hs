import Data.List

main :: IO()
main = output . solve . map read . words =<< getContents

output :: Bool -> IO()
output True = putStrLn "YES"
output False = putStrLn "NO"

solve :: [Int] -> Bool
solve (n:m:a) = let b = splitToTwoD m a
                    c = (0, 0) : [(i, j) | i <- [0..(m-2)], j <- [(i+1)..(m-1)]]
                in any (checkSwapCol b) c

splitToTwoD :: Int -> [Int] -> [[Int]]
splitToTwoD _ [] = []
splitToTwoD m a = let (b, c) = splitAt m a
                  in b : splitToTwoD m c

swapCol :: Int -> Int -> [Int] -> [Int]
swapCol i j a = let ei = a !! i
                    ej = a !! j
                in swapCol' ei ej 0 a
                where swapCol' :: Int -> Int -> Int -> [Int] -> [Int]
                      swapCol' _ _ _ [] = []
                      swapCol' ei ej c (a:s) | c == i = ej : swapCol' ei ej (c + 1) s
                                             | c == j = ei : swapCol' ei ej (c + 1) s
                                             | otherwise = a : swapCol' ei ej (c + 1) s

checkSwapCol :: [[Int]] -> (Int, Int) -> Bool
checkSwapCol b (i, j) = all (checkSwappedCol 1 0 . swapCol i j) b

checkSwappedCol :: Int -> Int -> [Int] -> Bool
checkSwappedCol _ c [] = c <= 2
checkSwappedCol i c (b:bs) | i == b = checkSwappedCol (i + 1) c bs
                           | otherwise = checkSwappedCol (i + 1) (c + 1) bs
