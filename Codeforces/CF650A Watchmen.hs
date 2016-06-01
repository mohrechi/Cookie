import Data.List
import Data.Maybe
import Data.Functor
import Data.Function (on)
import qualified Data.Map as Map
import qualified Data.ByteString.Char8 as B

main :: IO()
main = do
    _ <- getLine
    a <- readAllInts
    print $ solve $ selfZip a

readInt :: B.ByteString -> Int
readInt = fromJust . fmap fst . B.readInt

readAllInts :: IO [Int]
readAllInts = map readInt . B.words <$> B.getContents

count :: [[a]] -> Integer
count a = sum $ map ((\x -> x * (x - 1) `div` 2) . fromIntegral . length) a

solve :: [(Int, Int)] -> Integer
solve a = let sx = sort a
              sy = sortBy (compare `on` snd) a
              gx = groupBy ((==) `on` fst) sx
              gy = groupBy ((==) `on` snd) sy
              gxy = group sx
              cx = count gx
              cy = count gy
              cxy = count gxy
          in cx + cy - cxy

selfZip :: [Int] -> [(Int, Int)]
selfZip [] = []
selfZip (a:b:s) = (a, b):selfZip s
