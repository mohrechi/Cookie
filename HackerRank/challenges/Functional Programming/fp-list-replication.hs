f :: Int -> [Int] -> [Int]
f n arr = f' n arr 0 []
    where
        f' :: Int -> [Int] -> Int -> [Int] -> [Int]
        f' n [] i rep = rep
        f' n (x:xs) i rep = 
            if i < n then
                f' n (x:xs) (i+1) (rep++[x])
            else
                f' n xs 0 rep
             
main :: IO ()
main = getContents >>=
       mapM_ print. (\(n:arr) -> f n arr). map read. words
