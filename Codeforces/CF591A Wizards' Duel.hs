main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Float] -> Float
solve [l, p, q] = l * p / (p + q)
