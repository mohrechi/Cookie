main :: IO()
main = putStrLn . unwords . map show . solve . map read . tail . words =<< getContents

solve :: [Int] -> [Int]
solve a = let m = getMax a
          in solve' a (tail m)

solve' :: [Int] -> [Int] -> [Int]
solve' []    []     = []
solve' (a:s) (m:ms) | a > m     = 0 : solve' s ms
                    | otherwise = (m - a + 1) : solve' s ms

getMax :: [Int] -> [Int]
getMax []    = [0]
getMax (a:s) = let next = getMax s
               in (max a (head next)):next
