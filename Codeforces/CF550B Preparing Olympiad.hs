main :: IO()
main = print . solve . (map read . words) =<< getContents

solve :: [Int] -> Int
solve (_:l:r:x:c) = dfs c []
    where
        dfs :: [Int] -> [Int] -> Int
        dfs [] sub = valid sub
        dfs (c:cs) sub = (dfs cs sub) + (dfs cs (c:sub))
        
        valid :: [Int] -> Int
        valid sub = 
            let s = sum sub
                d = (maximum sub) - (minimum sub)
            in if l <= s && s <= r && d >= x then 1 else 0