import Data.List
import Data.Maybe (fromJust)
import Data.ByteString (ByteString)
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C

main :: IO()
main = putStrLn . unwords . map show . solve . map (fst . fromJust . C.readInteger) . C.words =<< B.getContents

solve :: [Integer] -> [Integer]
solve (n:a) = let sorted = sort a
                  relativeDist = sum $ calcRelativeDist 1 (head sorted) 0 (tail sorted)
                  absoluteDist = sum a
                  totalDist = 2 * relativeDist + absoluteDist
                  common = gcd totalDist n
              in  [div totalDist common, div n common]

calcRelativeDist :: Integer -> Integer -> Integer -> [Integer] -> [Integer]
calcRelativeDist i last dist []    = [dist]
calcRelativeDist i last dist (a:s) = dist : calcRelativeDist (i + 1) a (dist + i * (a - last)) s
