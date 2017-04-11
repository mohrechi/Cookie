import Data.List

main :: IO ()
main = print . minimum . zipWith (\x y -> y `div` x) [1, 1, 2, 7, 4] . map read . words =<< getLine
