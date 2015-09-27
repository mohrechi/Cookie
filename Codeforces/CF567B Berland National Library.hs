main :: IO()
main = print . solve . trans . tail . words =<< getContents

trans :: [String] -> [(Int, Int)]
trans []       = []
trans (op:r:s) | op == "+" = (1, (read r)):(trans s)
               | otherwise = (0, (read r)):(trans s)

solve :: [(Int, Int)] -> Int
solve r = solve' (reverse (complete (reverse r) [])) []
    where
        solve' :: [(Int, Int)] -> [Int] -> Int
        solve' []          a = length a
        solve' ((1, r):rs) a = solve' rs (insertTo a r)
        solve' ((0, r):rs) a = solve' rs (removeFrom a r)
        
removeElem :: [Int] -> Int -> [Int]
removeElem [] v     = []
removeElem (l:ls) v | l == v    = ls
                    | otherwise = l:(removeElem ls v)
                                
complete :: [(Int, Int)] -> [Int] -> [(Int, Int)]
complete [] []         = []
complete [] (c:cs)     = (1, c):(complete [] cs)
complete ((0, r):rs) c = (0, r):(complete rs (r:c))
complete ((1, r):rs) c = (1, r):(complete rs (removeElem c r))

insertTo :: [Int] -> Int -> [Int]
insertTo []     v = [v]
insertTo (0:rs) v = v:rs
insertTo (r:rs) v = r:(insertTo rs v)

removeFrom :: [Int] -> Int -> [Int]
removeFrom (r:rs) v | r == v    = 0:rs
                    | otherwise = r:(removeFrom rs v)
