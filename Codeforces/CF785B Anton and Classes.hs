import Data.List
import Data.Maybe (fromJust)
import Data.ByteString (ByteString)
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C

main :: IO()
main = print . solve . map (fst . fromJust . C.readInt) . C.words =<< B.getContents

solve :: [Int] -> Int
solve (n:a) = let (p, _:q) = splitAt (2 * n) a
                  (po, pe) = split p
                  (qo, qe) = split q
                  pomax = maximum po
                  pemin = minimum pe
                  qomax = maximum qo
                  qemin = minimum qe
                  int1 = if qomax > pemin then qomax - pemin else 0
                  int2 = if pomax > qemin then pomax - qemin else 0
              in max int1 int2
              
split :: [Int] -> ([Int], [Int])
split [] = ([], [])
split (x:y:s) = let (xs, ys) = split s in (x:xs, y:ys)
