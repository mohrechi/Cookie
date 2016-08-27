import Data.List
import Data.Maybe (fromJust)
import Data.ByteString (ByteString)
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C

main :: IO()
main = putStrLn . unwords . map show . solve . map (fst . fromJust . C.readInt) . C.words =<< B.getContents

solve :: [Int] -> [Int]
solve (n:m:a) = let b = transpose $ rect 0 [] a
                in solve' b (replicate n 0)
                where rect :: Int -> [Int] -> [Int] -> [[Int]]
                      rect _ l [] = [reverse l]
                      rect i l (a:s) | i == m = reverse l : rect 0 [] (a:s)
                                     | otherwise = rect (i + 1) (a:l) s

                      solve' :: [[Int]] -> [Int] -> [Int]
                      solve' s t = foldl (\ t l -> addTo (head t) l t) t s

                      addTo :: Int-> [Int] -> [Int] -> [Int]
                      addTo _ [] [] = []
                      addTo f (l:ls) (t:ts) = let nt = l + max f t
                                              in nt : addTo nt ls ts
