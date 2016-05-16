import Data.List
import Control.Arrow
import Control.Applicative
import Control.Monad
import qualified Data.Text as T
import qualified Data.Text.IO as TIO
import Data.Text.Read (decimal)
import System.IO (stdin)
import qualified Data.Map as Map

tread s = case decimal s of
    Right (v, _) -> v
    Left e -> error e

main :: IO()
main = do
    _ <- getLine
    a <- map tread . T.words <$> TIO.hGetLine stdin :: IO [Int]
    _ <- getLine
    b <- map tread . T.words <$> TIO.hGetLine stdin :: IO [Int]
    c <- map tread . T.words <$> TIO.hGetLine stdin :: IO [Int]
    let f = Map.fromList $ frequency a
    print $ solve b c 1 0 0 1 f

frequency :: Ord a => [a] -> [(a, Int)]
frequency = map (head &&& length) . group . sort

removeMaybe :: Maybe Int -> Int
removeMaybe (Just a) = a
removeMaybe Nothing = 0

solve :: [Int] -> [Int] -> Int -> Int -> Int -> Int -> Map.Map Int Int -> Int
solve [] [] _ _ _ maxIdx _ = maxIdx
solve (b:bs) (c:cs) idx maxVal1 maxVal2 maxIdx fre =
    let newVal1 = removeMaybe $ Map.lookup b fre
        newVal2 = removeMaybe $ Map.lookup c fre
    in if newVal1 > maxVal1 || (newVal1 == maxVal1 && newVal2 > maxVal2)
       then solve bs cs (idx + 1) newVal1 newVal2 idx fre
       else solve bs cs (idx + 1) maxVal1 maxVal2 maxIdx fre
