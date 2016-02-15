import Data.List

main :: IO()
main = print . solve . tail . words =<< getContents

chars :: [Char]
chars = ['a'..'z']

solve :: [String] -> Int
solve strs = last $ sort $ map (countNum (filter (\s -> (numOfDChar s) <= 2) strs)) [(x, y) | x <- chars, y <- chars]

numOfDChar :: String -> Int
numOfDChar s = sum $ map (\c -> if elem c s then 1 else 0) chars

countNum :: [String] -> (Char, Char) -> Int
countNum fed (x, y) = sum $ map length $ filter (\s -> and (map (\c -> c == x || c == y) s)) fed
