main :: IO()
main = output . solve . map read . words =<< getContents

solve :: [Int] -> Maybe [Int]
solve [n, k] | (div n 2) > k   = Nothing
             | n == 1 && k > 0 = Nothing
             | n == 1          = Just [1]
             | otherwise       = let a = div n 2
                                     b = k - (a - 1)
                                 in  Just (b:(b*2):(solve' (b*2 + 1) (n - 2)))

solve' :: Int -> Int -> [Int]
solve' _ 0 = []
solve' i n = i : (solve' (i + 1) (n - 1))

output :: Maybe [Int] -> IO()
output Nothing       = putStrLn "-1"
output (Just [])     = putStrLn ""
output (Just (a:ax)) = do putStr ((show a) ++ " ")
                          output (Just ax)
