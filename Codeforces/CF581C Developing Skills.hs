main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (n:k:a) = let b = getRem a (replicate 11 0)
                in  divide k b 0

addToList :: [Int] -> Int -> Int -> [Int]
addToList (a:s) 0 v = (a + v) : s
addToList (a:s) i v = a : (addToList s (i - 1) v)

getRem :: [Int] -> [Int] -> [Int]
getRem []    cnt = cnt
getRem (a:s) cnt = let next = (addToList (addToList cnt 0 (div a 10)) 10 (div (100 - (a + (rem (10 - (rem a 10)) 10))) 10))
                   in  if mod a 10 == 0 then getRem s next else getRem s (addToList next (10 - (rem a 10)) 1)

divide :: Int -> [Int] -> Int -> Int
divide k (b:bs) 0   = b + (divide k bs 1)
divide 0 (b:bs) _   = 0
divide k []     _   = 0
divide k (b:bs) idx | (div k idx) >= b = b + (divide (k - b * idx) bs (idx + 1))
                    | otherwise        = div k idx
