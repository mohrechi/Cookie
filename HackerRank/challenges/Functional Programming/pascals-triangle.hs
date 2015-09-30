pascal :: Int -> [[Int]]
pascal n = pascal' (n - 1) [1]
    where 
        pascal' :: Int -> [Int] -> [[Int]]
        pascal' 0 last = [last]
        pascal' i last = (last:(pascal' (i - 1) (next last 0)))
            where
                next :: [Int] -> Int -> [Int]
                next [] prev = [1]
                next (x:xs) prev = ((prev + x):(next xs x))
                
print_pascal :: [[Int]] -> IO()                
print_pascal [] = putStr ""
print_pascal (x:xs) = do 
    print_row x
    print_pascal xs
        where
            print_row :: [Int] -> IO()
            print_row [] = putStrLn ""
            print_row (x:xs) = do
                putStr (show x)
                putStr " "
                print_row xs

main = do
    input <- getLine
    print_pascal . pascal . (read :: String -> Int) $ input