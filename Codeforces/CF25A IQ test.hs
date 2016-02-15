import Data.List

main :: IO()
main = print . solve . map read . tail . words =<< getContents

removeMaybe :: Maybe a -> a
removeMaybe (Just a) = a

solve :: [Int] -> Int
solve a | length (filter odd a) == 1 = 1 + removeMaybe (findIndex odd a)
        | otherwise                  = 1 + removeMaybe (findIndex even a)
