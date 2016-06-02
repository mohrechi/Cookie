import Data.Char

main :: IO()
main = print . solve =<< getLine

toBase64 :: Char -> Int
toBase64 c | '0' <= c && c <= '9' = ord c - ord '0'
           | 'A' <= c && c <= 'Z' = ord c - ord 'A' + 10
           | 'a' <= c && c <= 'z' = ord c - ord 'a' + 36
           | c == '-' = 62
           | c == '_' = 63

numOf0 :: Int -> Integer
numOf0 = numOf0' 6
    where numOf0' :: Int -> Int -> Integer
          numOf0' 0 _ = 0
          numOf0' n x | even x = 1 + numOf0' (n - 1) (x `div` 2)
                      | otherwise = numOf0' (n - 1) (x `div` 2)

modC :: Integer
modC = 1000000007

pow :: Integer -> Integer -> Integer
x `pow` y | y == 0 = 1
          | y == 1 = x `mod` modC
          | odd y = x * (x `pow` (y - 1)) `mod` modC
          | even y = let x' = x `pow` (y `div` 2)
                 in x' * x' `mod` modC

solve :: String -> Integer
solve s = let m = sum $ map (numOf0 . toBase64) s
          in 3 `pow` m 
