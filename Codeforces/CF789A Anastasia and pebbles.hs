main :: IO ()
main = print . solve 0 0 . tail . map read . words =<< getContents

solve :: Int -> Int -> [Int] -> Int
solve sum single [_]      = sum + (single + 1) `div` 2
solve sum single (k:w:ws) = let pockets = (w + k - 1) `div` k
                            in solve (sum + pockets `div` 2) (single + pockets `mod` 2) (k:ws)
