main :: IO()
main = getContents >>= mapM_ print . solve . lines

solve :: [String] -> [Int]
solve (x:xs) = 
    let n = head (map read (words x))
        grids = map (map read . words) (take n xs)
        rounds = map (map read . words) (drop n xs)
        scores = map row_score grids
    in solve' grids scores rounds
        where 
            solve' :: [[Int]] -> [Int] -> [[Int]] -> [Int]
            solve' _  _ [] = []
            solve' grids scores ([x,y]:xs) = 
                let (new_grids, new_scores, val) = (solve_at grids scores x y)
                in val:(solve' new_grids new_scores xs)
            
            row_score :: [Int] -> Int
            row_score x = row_score' x 0
            
            row_score' :: [Int] -> Int -> Int
            row_score' [] cnt = cnt
            row_score' (x:xs) cnt | x == 1 = row_score' xs (cnt+1)
                                  | otherwise = max cnt (row_score' xs 0)
                                  
            solve_at :: [[Int]] -> [Int] -> Int -> Int -> ([[Int]], [Int], Int)
            solve_at grids scores x y =
                let new_grids = update_grid grids x y 1
                    new_scores = update_score new_grids scores x 1
                in (new_grids, new_scores, (max_score new_scores))
                                  
            update_grid :: [[Int]] -> Int -> Int -> Int -> [[Int]]
            update_grid [] _ _ _ = []
            update_grid (g:gs) x y r | x == r = (update_row g y 1):(update_grid gs x y (r+1))
                                     | otherwise = g:(update_grid gs x y (r+1))
                                     
            update_score :: [[Int]] -> [Int] -> Int -> Int -> [Int]
            update_score [] [] _ _ = []
            update_score (g:gs) (s:ss) x r | x == r = (row_score g):(update_score gs ss x (r+1))
                                           | otherwise = s:(update_score gs ss x (r+1))
                                           
            max_score :: [Int] -> Int
            max_score [] = 0
            max_score (x:xs) = max x (max_score xs)
                                  
            update_row :: [Int] -> Int -> Int -> [Int]
            update_row [] _ _ = []
            update_row (x:xs) y c | y == c = (1-x):(update_row xs y (c+1))
                                  | otherwise = x:(update_row xs y (c+1))