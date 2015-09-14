import Data.List

main :: IO()
main = output . solve . map read . words =<< getContents

solve :: [Integer] -> [Integer]
solve [a, b, c] = solve' 81
    where
        solve' :: Integer -> [Integer]
        solve' 0  = []
        solve' sx = let x = b * sx ^ a + c
                    in  if sx == (digitSum x) 
                        then x:(solve' (sx - 1))
                        else solve' (sx - 1)
        
digitSum :: Integer -> Integer
digitSum 0 = 0
digitSum a | a < 0           = 0
           | a >= 1000000000 = 0
           | otherwise       = (mod a 10) + (digitSum (div a 10))

output :: [Integer] -> IO()
output a = do putStrLn (show (length a))
              output' (sort a)
              
output' :: [Integer] -> IO()
output' []     = putStrLn ""
output' (a:ax) = do putStr (show a)
                    putStr " "
                    output' ax
