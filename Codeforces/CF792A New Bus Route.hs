import Data.List
import Data.Maybe (fromJust)
import Data.ByteString (ByteString)
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = putStrLn . unwords . map show . solve . tail . map (fst . fromJust . C.readInt) . C.words =<< B.getContents

solve :: [Int] -> [Int]
solve a = solve' [maxBound :: Int, 0] (sort a)

solve' :: [Int] -> [Int] -> [Int]
solve' result [] = result
solve' result [a] = result
solve' [d, c] (a:b:x) | b - a < d = solve' [b - a, 1] (b:x)
                      | b - a == d = solve' [d, c + 1] (b:x)
                      | otherwise = solve' [d, c] (b:x)
