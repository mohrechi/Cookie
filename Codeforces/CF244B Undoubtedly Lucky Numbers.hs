import Data.Bits

main :: IO()
main = print . solve . read =<< getLine

solve :: Int -> Int
solve n = num
    where
        nums1 = map (\x -> compose1 x 0 0) [1..9]
        nums2 = map (\(x, y) -> compose2 x y 0 0 0) [(x, y) | x <- [0..8], y <- [(x+1)..9]]
        num = sum $ map (length . filter (<=n)) ([1000000000]:(nums1 ++ nums2))

compose1 :: Int -> Int -> Int -> [Int]
compose1 _ num 9 = [num]
compose1 x num i = case i of 0 -> longer
                             _ -> num:longer
                   where longer = compose1 x (num * 10 + x) (i + 1)

compose2 :: Int -> Int -> Int -> Int -> Int -> [Int]
compose2 _ _ num 9 3 = [num]
compose2 _ _ num 9 _ = []
compose2 x y num i s | num == 0 && x == 0 = compose2 x y y (i + 1) (s .|. 2)
                     | otherwise = case s of 3 -> num:longer
                                             _ -> longer
                                   where longer = (compose2 x y (num * 10 + x) (i + 1) (s .|. 1)) ++ 
                                                  (compose2 x y (num * 10 + y) (i + 1) (s .|. 2))
