import qualified Data.Set as Set

main :: IO()
main = putStrLn . unwords . map show . solve . map read . tail . words =<< getContents

getVal :: (Set.Set (Int, Int) -> (Int, Int)) -> Set.Set (Int, Int) -> (Int, Int)
getVal f s | Set.null s = (-1, -1)
           | otherwise = f s

getMin :: Set.Set (Int, Int) -> (Int, Int)
getMin = getVal Set.findMin

getMax :: Set.Set (Int, Int) -> (Int, Int)
getMax = getVal Set.findMax

solve :: [Int] -> [Int]
solve (a:ax) = solve' 1 ax (Set.singleton (a, 0))
    where solve' :: Int -> [Int] -> Set.Set (Int, Int) -> [Int]
          solve' _ [] _ = []
          solve' i (a:ax) s = let (l, r) = Set.split (a, 0) s
                                  (lv, lt) = getMax l
                                  (rv, rt) = getMin r
                                  next_s = Set.insert (a, i) s
                              in if lt > rt
                                 then lv:solve' (i + 1) ax next_s
                                 else rv:solve' (i + 1) ax next_s
