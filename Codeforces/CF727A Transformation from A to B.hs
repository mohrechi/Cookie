main :: IO()
main = output . solve . map read . words =<< getLine

output :: [Integer] -> IO()
output [] = putStrLn "NO"
output a = do
    putStrLn "YES"
    putStrLn $ show $ length a
    putStrLn $ unwords $ map show a

solve :: [Integer] -> [Integer]
solve  [a, b] = solve' [a]
    where solve' :: [Integer] -> [Integer]
          solve' path | head path > b = []
                      | head path == b = reverse path
                      | otherwise = let c = (head path) * 2
                                        r = solve' (c : path)
                                    in if length r > 0
                                       then r
                                       else solve' ((head path) * 10 + 1 : path)
