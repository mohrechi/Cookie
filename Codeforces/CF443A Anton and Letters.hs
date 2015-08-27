import Data.List

main :: IO()
main = interact $ show . length . nub . filter (\c -> 'a' <= c && c <= 'z')
