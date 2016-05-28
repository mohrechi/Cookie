import Data.List

main :: IO()
main = output . solve . nub . sort . map read . tail . words =<< getContents

solve :: [Int] -> Bool
solve [] = False
solve [a] = False
solve [a, b] = False
solve (a:b:c:x) = (a + 1 == b && b + 1 == c) || solve (b:c:x)

output :: Bool -> IO()
output True = putStrLn "YES"
output False = putStrLn "NO"

