import Data.Function (on)
import Data.List (sortBy)

main :: IO()
main = getContents >>= putStrLn . solve . lines
    
solve :: [String] -> String
solve inputs =
    let n = read (head inputs)
        a = map read (words (head (tail inputs)))
        ans = solves n a
    in to_s ans
        where
            solves :: Int -> [Int] -> [Int]
            solves n a = let left = get_left a [] [] 1
                             right = reverse (get_left (reverse a) [] [] 1)
                             c = comb left right
                         in take n (accum n (get_min a) (sortBy (compare `on` snd) c) 1)
            
            get_left :: [Int] -> [Int] -> [Int] -> Int -> [(Int, Int)]
            get_left [] _ _ _ = []
            get_left (a:ax) [] [] idx = (a,idx):(get_left ax [idx] [a] (idx+1))
            get_left (a:ax) (si:sis) (sa:sas) idx | sa >= a = get_left (a:ax) sis sas idx
                                                  | otherwise = (a,idx-si):(get_left ax (idx:si:sis) (a:sa:sas) (idx+1))
                                                  
            comb :: [(Int, Int)] -> [(Int, Int)] -> [(Int, Int)]
            comb [] [] = []
            comb ((la,li):ls) ((ra,ri):rs) = (la, li + ri - 1):(comb ls rs)
                                                  
            get_min :: [Int] -> Int
            get_min [x] = x
            get_min (x:xs) = min x (get_min xs)
                                                  
            accum :: Int -> Int -> [(Int, Int)] -> Int -> [Int]
            accum n m [] idx | idx <= n = m:(accum n m [] (idx+1))
                             | otherwise = [0]
            accum n m ((a,i):xs) idx | idx > i = accum n m xs idx
                                     | idx == i = let r = accum n m xs idx
                                                  in (max a (head r)):(tail r)
                                     | otherwise = let r = accum n m ((a,i):xs) (idx+1)
                                                   in (head r):r
        
            to_s :: [Int] -> String
            to_s [] = ""
            to_s (x:xs) = (show x) ++ " " ++ (to_s xs)