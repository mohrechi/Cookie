import Data.List

main :: IO()
main = printResult . solve . map read . words =<< getContents

printResult :: Bool -> IO()
printResult b = putStrLn (if b then "I become the guy." else "Oh, my keyboard!")

solve :: [Int] -> Bool
solve (n:na:x) =
    let a = take na x
        b = drop (na + 1) x
    in  (length $ nub (a ++ b)) == n
