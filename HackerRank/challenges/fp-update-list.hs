f [] = []
f (x:xs) = ((abs x):(f xs))

main = do
   inputdata <- getContents
   mapM_ putStrLn $ map show $ f $ map (read :: String -> Int) $ lines inputdata
