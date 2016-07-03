import Data.List

main :: IO()
main = print . solve . tail . lines =<< getContents

solve :: [String] -> Int
solve = maximum . (++) [0] . map length . filter head . group . map check

check :: String -> Bool
check s = length (filter (== '0') s) > 0
