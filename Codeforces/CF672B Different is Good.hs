import Data.List

main :: IO()
main = do
    sn <- getLine
    let n = read sn
    s <- getLine
    print $ solve n s

solve :: Int -> String -> Int
solve n s | n > 26 = -1
          | otherwise = n - length (nub s)
