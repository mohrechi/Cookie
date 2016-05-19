main :: IO()
main = output . solve . map read . words =<< getLine

solve :: [Double] -> Maybe Double
solve [d, h, v, e] | pi / 4.0 * d * d * e > v = Nothing
                   | otherwise = Just ((pi / 4.0 * d * d * h) / (v - pi / 4.0 * d * d * e))

output :: Maybe Double -> IO()
output Nothing = putStrLn "NO"
output (Just x) = putStrLn $ "YES\n" ++ show x
