import Data.Char

main :: IO()
main = print . solve . words =<< getContents

solve :: [String] -> Int
solve (a:b:c:d:s:_) = solve' (map read [a, b, c, d]) s

solve' :: [Int] -> String -> Int
solve' _ "" = 0
solve' a (s:ss) = a !! (ord s - ord '1') + solve' a ss
