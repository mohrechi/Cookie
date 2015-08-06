main :: IO()
main = output . solve . map read . words =<< getContents

solve :: [Int] -> [[Int]]
solve (n:x) = 
    let   x1 = head x
          xn = last x
    in    solve' x1 xn x 0 True
    where solve' :: Int -> Int -> [Int] -> Int -> Bool -> [[Int]]
          solve' x1 xn (x:xs) _    True = ([(head xs) - x, xn - x]:(solve' x1 xn xs x False))
          solve' x1 xn [x]    last _    = [[(x - last), x - x1]]
          solve' x1 xn (x:xs) last _    = ([(min (x - last) ((head xs) - x)), (max (x - x1) (xn - x))]:(solve' x1 xn xs x False))

output :: [[Int]] -> IO()
output [[a, b]] = output' [a, b]
output (x:xs)   = do output' x
                     output xs

output' :: [Int] -> IO()
output' [a, b] = putStrLn ((show a) ++ " " ++ (show b))
