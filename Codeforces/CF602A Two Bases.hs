import Data.List

main :: IO()
main = output . solve . map read . words =<< getContents

output :: (Integer, Integer) -> IO()
output (a, b) | a > b = putStrLn ">"
              | a < b = putStrLn "<"
              | otherwise = putStrLn "="

solve :: [Integer] -> (Integer, Integer)
solve (n:bx:s) = let (x, (m:by:y)) = splitAt (fromIntegral n) s
                 in (construct bx x 0, construct by y 0)

construct :: Integer -> [Integer] -> Integer -> Integer
construct _ []    num = num
construct b (x:s) num = construct b s (num * b + x)
