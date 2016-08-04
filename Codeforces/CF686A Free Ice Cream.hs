main :: IO()
main = putStrLn . unwords . map show . solve . tail . words =<< getContents

solve :: [String] -> [Integer]
solve (xs:cs) = solve' (read xs) 0 cs

solve' :: Integer -> Integer -> [String] -> [Integer]
solve' x c [] = [x, c]
solve' x c (o:ds:s) | o == "+" = solve' (x + read ds) c s
                    | otherwise = let d = read ds
                                  in if x >= d
                                     then solve' (x - d) c s
                                     else solve' x (c + 1) s
