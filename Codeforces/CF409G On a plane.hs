main :: IO ()
main = print . solve . map read . tail . words =<< getContents

solve :: [Double] -> Double
solve a = let b = map fst $ filter (odd . snd)  $ zip a [0..]
          in  5.0 + sum b / fromIntegral (length b)
