main :: IO()
main = do
    line <- getLine
    let ans = solve . map read . words $ line
    print (head ans)
    putStrLn $ unwords $ map show (tail ans)

solve :: [Integer] -> [Integer]
solve [n, a, b] | a * b >= 6 * n = [a * b, a, b]
                | a > b = let [s, b', a'] = solve' b a [36 * n * n] in [s, a', b']
                | otherwise = solve' a b [36 * n * n]
    where solve' :: Integer -> Integer -> [Integer] -> [Integer]
          solve' a b (s:ss) | a * a >= 6 * n = s:ss
                            | otherwise = let bb = max b (div (6 * n + a - 1) a)
                                              ns = a * bb
                                          in if ns < s
                                             then solve' (a + 1) b [ns, a, bb]
                                             else solve' (a + 1) b (s:ss)
