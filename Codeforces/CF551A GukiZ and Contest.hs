main :: IO()
main = putStrLn . unwords . map show . solve . tail . map read . words =<< getContents

solve :: [Int] -> [Int]
solve a = map (\x -> 1 + length (filter (> x) a)) a
