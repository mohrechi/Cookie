f [] = 0
f (x:xs) = if odd x then x + (f xs) else f xs

main = do
   inputdata <- getContents
   putStrLn $ show $ f $ map (read :: String -> Int) $ lines inputdata
