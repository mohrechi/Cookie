import Data.List
import qualified Data.Set as Set

main :: IO()
main = output . solve . tail . lines =<< getContents

output :: Bool -> IO()
output True  = putStrLn "YES"
output False = putStrLn "NO"

solve :: [String] -> Bool
solve strs = let n = length strs
                 s = foldl1 Set.union (map (initSet 0) (zip strs [0..]))
             in check n 0 0 s

initSet :: Int -> (String, Int) -> Set.Set (Int, Int)
initSet _   ("",     _)   = Set.empty
initSet col (s : ss, row) = let next = initSet (col + 1) (ss, row)
                            in if s == '#' 
                               then Set.insert (row, col) next
                               else next

check :: Int -> Int -> Int -> Set.Set (Int, Int) -> Bool
check n r c s | r >= n = True
              | c >= n = check n (r + 1) 0 s
              | Set.member (r, c) s = Set.member (r + 1, c - 1) s &&
                                      Set.member (r + 1, c    ) s &&
                                      Set.member (r + 1, c + 1) s &&
                                      Set.member (r + 2, c    ) s &&
                                      (check n r (c + 1) $ Set.delete (r + 1, c - 1) $
                                                           Set.delete (r + 1, c    ) $
                                                           Set.delete (r + 1, c + 1) $
                                                           Set.delete (r + 2, c    ) s)
              | otherwise = check n r (c + 1) s
