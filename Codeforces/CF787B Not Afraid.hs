import Data.List
import Data.Maybe (fromJust)
import Data.ByteString (ByteString)
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = output . solve . drop 2 . map (fst . fromJust . C.readInt) . C.words =<< B.getContents

output :: Bool -> IO ()
output True = putStrLn "NO"
output False = putStrLn "YES"

solve :: [Int] -> Bool
solve [] = True
solve (n:x) = let (a, s) = splitAt n x
                  r = sort $ filter (> 0) a
                  m = sort $ map abs $ filter (< 0) a
              in check r m && solve s

check :: [Int] -> [Int] -> Bool
check [] _ = False
check _ [] = False
check (a:ax) (b:bx) | a == b    = True
                    | a < b     = check ax (b:bx)
                    | otherwise = check (a:ax) bx
