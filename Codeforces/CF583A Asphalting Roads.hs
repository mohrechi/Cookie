import Data.List
import qualified Data.Set as Set

main :: IO()
main = putStrLn . intercalate " " . map show . solve 1 Set.empty Set.empty . map read . tail . words =<< getContents

solve :: Int -> Set.Set Int -> Set.Set Int -> [Int] -> [Int]
solve _ _ _ [] = []
solve i h v (x:y:s) | (Set.member x h) || (Set.member y v) = solve (i + 1) h v s
                    | otherwise = i : solve (i + 1) (Set.insert x h) (Set.insert y v) s
