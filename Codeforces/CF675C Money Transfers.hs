import qualified Data.Map as Map

main :: IO()
main = do
    sn <- getLine
    sa <- getLine
    let n = read sn
    let a = map read $ words sa
    print $ solve n a Map.empty 0 n

removeMaybe :: Maybe Int -> Int
removeMaybe (Just a) = a
removeMaybe Nothing = 0

solve :: Int -> [Integer] -> Map.Map Integer Int -> Integer -> Int -> Int
solve _ [] _ _ ans = ans
solve n (a:ax) cnt sum ans = let next_sum = sum + a
                                 num = 1 + (removeMaybe $ Map.lookup next_sum cnt)
                                 deleted = Map.delete next_sum cnt
                                 next_cnt = Map.insert next_sum num deleted
                             in solve n ax next_cnt next_sum (min ans (n - num))
