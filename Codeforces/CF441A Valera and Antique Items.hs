import Data.List

main :: IO()
main = output . solve . map (map read . words) . lines =<< getContents

output :: [Int] -> IO()
output (a:ax) = putStrLn ((show a) ++ "\n" ++ (unwords (map show ax)))

solve :: [[Int]] -> [Int]
solve ([n, v]:a) = 
    let ans = solve' a 1
    in ((length ans):ans)
    where solve' :: [[Int]] -> Int -> [Int]
          solve' []          _ = []
          solve' ((w:ws):ax) i | v > (minimum ws) = (i:(solve' ax (i + 1)))
                               | otherwise        = solve' ax (i + 1)
