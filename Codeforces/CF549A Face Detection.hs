import Data.List

main :: IO()
main = print . solve . tail . lines =<< getContents

solve :: [String] -> Int
solve (a:b:s) = (count (zips a b)) + (solve (b:s))
solve _       = 0

zips :: String -> String -> String
zips ""     ""     = ""
zips (a:as) (b:bs) = (a:b:(zips as bs))

count :: String -> Int
count (a:b:c:d:s) | sort [a,b,c,d] == sort "face" = 1 + (count (c:d:s))
                  | otherwise = count (c:d:s)
count _           = 0