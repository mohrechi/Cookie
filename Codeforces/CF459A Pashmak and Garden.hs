main :: IO()
main = putStrLn . unwords . map show . solve . map read . words =<< getContents

solve :: [Int] -> [Int]
solve (x1:y1:x2:y2:_) = let a = abs (x1 - x2)
                            b = abs (y1 - y2)
                        in case () of _ | a == 0 -> [x1 + b, y1, x2 + b, y2]
                                        | b == 0 -> [x1, y1 + a, x2, y2 + a]
                                        | a /= b -> [-1]
                                        | otherwise -> [x1, y2, x2, y1]
