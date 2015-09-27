main = print . solve . map read . words =<< getContents
sign a x b y c = a * x + b * y + c > 0
solve (x1:y1:x2:y2:n:lines) = solve' lines
    where
        solve' []        = 0
        solve' (a:b:c:s) | (sign a x1 b y1 c) /= (sign a x2 b y2 c) = 1 + (solve' s)
                         | otherwise                                = solve' s
