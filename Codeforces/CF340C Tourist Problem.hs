import Data.List

main :: IO()
main = putStrLn . unwords . map show . solve . map read . words =<< getContents

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
