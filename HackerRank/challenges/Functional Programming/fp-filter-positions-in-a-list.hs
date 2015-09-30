f :: [Int] -> [Int]
f lst = f' lst 0
    where
        f' :: [Int] -> Int -> [Int]
        f' [] i = []
        f' (x:xs) i = if odd i then (x:(f' xs (i+1))) else f' xs (i+1)

main = do
   inputdata <- getContents
   mapM_ (putStrLn. show). f. map read. lines $ inputdata
