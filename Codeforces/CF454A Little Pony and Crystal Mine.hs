import Data.List

main = putStrLn . unlines . solve . read =<< getLine

solve :: Int -> [String]
solve n = solve' 1 True
    where solve' :: Int -> Bool -> [String]
          solve' x inc | x < 0 = []
                       | x > n = solve' (x - 4) False
                       | otherwise = let f = div (n - x) 2
                                         s = replicate f '*' ++ replicate x 'D' ++ replicate f '*'
                                     in if inc
                                        then s:solve' (x + 2) inc
                                        else s:solve' (x - 2) inc
