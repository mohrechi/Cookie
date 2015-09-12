main = print . solve . map read . words =<< getContents
solve c = solve' (sum c)
solve' s | s == 0        = -1
         | (mod s 5) > 0 = -1
         | otherwise     = div s 5
