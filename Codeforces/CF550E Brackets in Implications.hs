main :: IO()
main = solve . (map read . words) =<<getContents

solve :: [Int] -> IO()
solve (_:a) =
    let 
        zeroNum = length $ filter (==0) a
        ra = reverse a
        na = reverse $ tail ra
        r1 = head ra
        r2 = head $ tail ra
        invalid = (r1 == 1) || (zeroNum == 2 && r2 == 0)
    in 
        if invalid then 
            putStrLn "NO"
        else
            if (null na) then 
                putStrLn "YES\n0" 
            else do putStr "YES\n("
                    firstZero na True
                    putStrLn "->0)"
    where
        firstZero :: [Int] -> Bool -> IO()
        firstZero []     _              = putStr ")"
        firstZero (a:ax) True  | a == 0 = do putStr "(0->("
                                             incLast ax
                                             putStr "))"
                               | a == 1 = do putStr "(1"  
                                             firstZero ax False
        firstZero (a:ax) False | a == 0 = do putStr "->(0->("
                                             incLast ax
                                             putStr ")))"
                               | a == 1 = do putStr "->1"
                                             firstZero ax False
        
        incLast :: [Int] -> IO()
        incLast (a:ax) | null ax   = putStr $ show a
                       | otherwise = do putStr $ show a
                                        putStr "->"
                                        incLast ax
