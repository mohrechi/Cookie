import Data.List

main :: IO ()
main = output . solve [] . map read . tail . words =<< getContents

output :: Bool -> IO ()
output True = putStrLn "YES"
output False = putStrLn "NO"

solve :: [Int] -> [Int] -> Bool
solve final [] | length final <= 2  = True
               | length final == 3 = let [a, b, c] = sort final
                                     in a + c == b + b
solve s (a:ax) | a `elem` s = solve s ax
               | length s == 3 = False
               | otherwise = solve (a:s) ax
