import Data.List

main :: IO()
main = putStrLn . solve . map read . words =<< getLine

solve :: [Int] -> String
solve a | last b < 4 = "Alien"
        | head b > 1 = "Elephant"
        | otherwise  = "Bear"
        where b = sort . map (\x -> length x) . group $ sort a
