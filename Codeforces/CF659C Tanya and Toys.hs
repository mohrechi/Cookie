import Data.List
import Data.Functor

main :: IO()
main = do
    [n, m] <- map read . words <$> getLine
    a <- sort . map read . words <$> getLine
    let r = solve m 1 a []
    print $ length r
    putStrLn $ unwords $ map show r

bound :: Int
bound = 1000000000

solve :: Int -> Int -> [Int] -> [Int] -> [Int]
solve m i a r | m < i = r
              | i > bound = r
              | otherwise = if null a
                            then solve (m - i) (i + 1) a (i:r)
                            else let (av:ax) = a
                                 in if i < av
                                    then solve (m - i) (i + 1) a (i:r)
                                    else if i == av
                                         then solve m (i + 1) ax r
                                         else solve m i ax r
