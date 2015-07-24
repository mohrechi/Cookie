main :: IO()
main = printBool . solve . map read . words =<< getContents

printBool :: Bool -> IO()
printBool b = putStrLn (if b then "YES" else "NO")

solve :: [Int] -> Bool
solve (a1:b1:a2:b2:a3:b3:_) = 
    let test1 = test a2 b2 a3 b3
        test2 = test b2 a2 a3 b3
        test3 = test a2 b2 b3 a3
        test4 = test b2 a2 b3 a3
    in test1 || test2 || test3 || test4
    where test :: Int -> Int -> Int -> Int -> Bool
          test a2 b2 a3 b3 = ((a2 + a3 <= a1) && (b2 <= b1) && (b3 <= b1)) || 
                             ((b2 + b3 <= b1) && (a2 <= a1) && (a3 <= a1))
