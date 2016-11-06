import Data.List

main :: IO()
main = output . solve . map read . words =<< getContents

output :: (Int, [Int]) -> IO()
output (cost, a) = do
    print cost
    putStrLn $ unwords $ map show a

solve :: [Int] -> (Int, [Int])
solve (n:k:a) = solve' (head a) (tail a) 0 [head a]
                where solve' :: Int -> [Int] -> Int -> [Int] -> (Int, [Int])
                      solve' last [] cost path = (cost, reverse path)
                      solve' last (a:x) cost path = let extra = max 0 (k - a - last)
                                                        walk = a + extra
                                                    in solve' walk x (cost + extra) (walk : path)
