import Data.List

main :: IO ()
main = putStrLn . unwords . map show . solve . map read . words =<< getContents

solve :: [Int] -> [Int]
solve (n:_:a) = solve' n [1..n] a

solve' :: Int -> [Int] -> [Int] -> [Int]
solve' _ _ [] = []
solve' n q (a:ax) = let (rear, front) = splitAt (a `mod` n) q
                    in  if null front
                        then head rear : solve' (n - 1) (tail rear) ax
                        else head front : solve' (n - 1) (tail front ++ rear) ax
