import Data.Char

main :: IO()
main = putStrLn . solve . head . words =<< getContents

solve :: String -> String
solve s = 
    if (length [x | x <- s, isLower x]) >= (length [x | x <- s, isUpper x])
    then map toLower s
    else map toUpper s
