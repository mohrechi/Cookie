import qualified Data.Map as Map

main :: IO()
main = getContents >>= mapM_ putStrLn . solve . map (map read . words) . lines

solve :: [[Int]] -> [String]
solve input = 
    let n = head $ head input
        x = head $ tail input
        m = Map.fromList $ getMap x 1
    in gen m 1 n
    where 
        getMap :: [Int] -> Int -> [(Int, Int)]
        getMap [] _ = []
        getMap (x:xs) i = (x, i):(getMap xs (i + 1))
        
        gen :: Map.Map Int Int -> Int -> Int -> [String]
        gen m i n | i > n = []
                  | otherwise = (show $ eliminate $ Map.lookup i m):(gen m (i + 1) n)
                  
        eliminate (Just a) = a