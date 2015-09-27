import Data.List

main :: IO()
main = printBool . solve . map read . words =<< getContents

printBool :: Bool -> IO()
printBool b  = putStrLn $ if b then "YES" else "NO"

solve :: [Int] -> Bool
solve (na:nb:k:m:x) =
    let a = (sort $ take na x) !! (k - 1)
        b = (sort $ drop na x) !! (nb - m)
    in  a < b
