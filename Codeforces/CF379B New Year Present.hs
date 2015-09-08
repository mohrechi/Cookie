main :: IO()
main = solve . tail . map read . words =<< getContents

solve :: [Int] -> IO()
solve [a]    | a == 0    = putStrLn ""
             | a == 1    = putStrLn "P"
             | otherwise = do putStr "PLR"
                              solve [(a-1)]
solve (a:ax) | a == 0    = do putStr "R"
                              solve ax
             | otherwise = do putStr "PRL"
                              solve ((a-1):ax)
