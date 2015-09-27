main :: IO()
main = print . solve . read =<< getLine

solve :: Int -> Int
solve a = (last $ a:(takeWhile notLucky [(a+1)..])) - a + 1

notLucky :: Int -> Bool
notLucky 0 = True
notLucky a | a < 0           = notLucky (abs a)
           | (mod a 10) == 8 = False
           | otherwise       = notLucky (div a 10)
