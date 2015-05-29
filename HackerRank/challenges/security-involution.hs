import qualified Data.Map as Map

main :: IO()
main = getContents >>= putStrLn . solve . map (map read . words) . lines

solve :: [[Int]] -> String
solve input = 
    let n = head $ head input
        x = head $ tail input
        m = Map.fromList $ getMap x 1
    in gen m 1 n
    where 
        getMap :: [Int] -> Int -> [(Int, Int)]
        getMap [] _ = []
        getMap (x:xs) i = (i, x):(getMap xs (i + 1))
        
        gen :: Map.Map Int Int -> Int -> Int -> String
        gen m i n | i > n = "YES"
                  | (eliminate $ Map.lookup (eliminate (Map.lookup i m)) m) == i = gen m (i + 1) n
                  | otherwise = "NO"
                  
        eliminate (Just a) = a