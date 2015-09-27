import Data.List

main :: IO()
main = output . solve . map read . words =<< getContents

output :: (Int, Integer) -> IO()
output (a, b) = putStrLn ((show a) ++ " " ++ (show b))

solve :: [Int] -> (Int, Integer)
solve (n:b) = let ni = toInteger n
                  low = minimum b
                  high = maximum b
                  lowNum = toInteger $ length (filter (== low) b)
                  highNum = toInteger $ length (filter (== high) b)
              in  if high == low then (0, (div (ni * (ni - 1)) 2))
                  else ((high - low), lowNum * highNum)
