import Data.List

main :: IO ()
main = print . minimum . zipWith (flip div) [1, 1, 2, 7, 4] . map read . words =<< getLine
