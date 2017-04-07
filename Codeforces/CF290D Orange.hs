import Data.Char

main :: IO ()
main = putStrLn . solve . words =<< getContents

solve :: [String] -> String
solve [s, sa] = let a = chr $ (ord 'a') + (read sa) - 1
                in solve' s a
                where solve' :: String -> Char -> String
                      solve' []    a = []
                      solve' (c:s) a | toLower c <= a = toUpper c : solve' s a
                                     | otherwise = toLower c : solve' s a
