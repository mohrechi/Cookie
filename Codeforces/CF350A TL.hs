main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (n:_:s) = let a = take n s
                    b = drop n s
                    v = max ((minimum a) * 2) (maximum a)
                    e = minimum b
                in  if v < e then v else -1
