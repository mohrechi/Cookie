import Data.List

main :: IO()
main = print . solve . head . tail . words =<< getContents

removeMaybe :: Int -> Maybe Int -> Int
removeMaybe _ (Just a) = a
removeMaybe n Nothing  = n

solve :: String -> Int
solve s = let n = length s
              l = removeMaybe n $ findIndex (== '>') s
              r = removeMaybe n $ findIndex (== '<') $ reverse s
          in l + r
