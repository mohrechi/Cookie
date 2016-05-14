main :: IO()
main = putStrLn . solve . read =<< getLine

prefix :: String
prefix = foldl1 (++) $ map show [1..400]

solve :: Int -> String
solve n = [prefix !! (n - 1)]
