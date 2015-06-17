main = getContents >>= print . solve . lines
    
solve inputs =
    let m = read (head inputs)
        pairs = get_pairs (tail inputs)
        (h1, a1) = head pairs
        (x1, y1) = head (tail pairs)
        (h2, a2) = head (drop 2 pairs)
        (x2, y2) = head (drop 3 pairs)
        f1 = get_first x1 y1 h1 a1 m 0
        f2 = get_first x2 y2 h2 a2 m 0
        l1 = get_loop x1 y1 a1 m
        l2 = get_loop x2 y2 a2 m
    in solve' f1 f2 l1 l2 m 0
        where
            get_pair s = 
                let p = map read (words s)
                in ((head p), (head (tail p)))
                
            get_pairs [] = []
            get_pairs (x:xs) = (get_pair x):(get_pairs xs)
            
            get_first x y h a m i | i > m = 0 - m - m
                                  | h == a = 0
                                  | otherwise = 1 + (get_first x y (rem (h * x + y) m) a m (i+1))
                                
            get_loop x y a m = 1 + (get_first x y (rem (a * x + y) m) a m 0)
            
            solve' f1 f2 l1 l2 m i | f1 < 0 || f2 < 0 || i > 2 * m = -1
                                   | f1 == f2 = f1
                                   | f1 < f2 = solve' (f1+l1) f2 l1 l2 m (i+1)
                                   | otherwise = solve' f1 (f2+l2) l1 l2 m (i+1)