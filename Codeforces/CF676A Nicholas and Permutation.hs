import Data.List

main :: IO()
main = print . removeJust . solve . map read . words =<< getContents

removeJust :: Maybe Int -> Int
removeJust (Just a) = a

solve :: [Int] -> Maybe Int
solve (n:a) = do
    x <- elemIndex 1 a
    y <- elemIndex n a
    return $ maximum [x, y, n - x - 1, n - y - 1]
