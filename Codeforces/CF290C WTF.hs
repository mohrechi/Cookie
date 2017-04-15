import Text.Printf
import Data.List

main :: IO ()
main = printf "%.6f" . solve . map read . tail . words =<< getContents

solve :: [Double] -> Double
solve a = maximum $ zipWith (/) (scanl1 (+) a) [1..]
