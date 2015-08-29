main :: IO()
main = output . solve . tail . map read . words =<< getContents

solve :: [Int] -> [(Int, Int, Int)]
solve a = solve' a a a 1 1 1

solve' :: [Int] -> [Int] -> [Int] -> Int -> Int -> Int -> [(Int, Int, Int)]
solve' []     _      _      _  _  _  = []
solve' _      []     _      _  _  _  = []
solve' _      _      []     _  _  _  = []
solve' (a:ax) (b:bx) (c:cx) ia ib ic | a /= 1    = solve' ax (b:bx) (c:cx) (ia + 1) ib ic
                                     | b /= 2    = solve' (a:ax) bx (c:cx) ia (ib + 1) ic
                                     | c /= 3    = solve' (a:ax) (b:bx) cx ia ib (ic + 1)
                                     | otherwise = (ia, ib, ic) : (solve' ax bx cx (ia + 1) (ib + 1) (ic + 1))

output :: [(Int, Int, Int)] -> IO()
output ans = do
    print (length ans)
    output' ans
    
output' :: [(Int, Int, Int)] -> IO()
output' [] = putStrLn ""
output' ((a, b, c):x) = do
    putStrLn (unwords (map show [a, b, c]))
    output' x
