import Data.List

main :: IO()
main = putStrLn . solve . lines =<< getContents

keyboard :: String
keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./"

removeMaybe :: Maybe a -> a
removeMaybe (Just a) = a

solve :: [String] -> String
solve (d:s:_) = if d == "R" then (solve' (-1) s) else (solve' 1 s)

solve' :: Int -> String -> String
solve' d "" = ""
solve' d (c:s) = (keyboard !! ((removeMaybe (elemIndex c keyboard)) + d)) : (solve' d s)
