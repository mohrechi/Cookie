main :: IO()
main = output . solve . map read . words =<< getContents

output :: Bool -> IO()
output b = putStrLn $ if b then "YES" else "NO"

solve :: [Integer] -> Bool
solve (n:a:_) = solve' 0 0 0 a
    where solve' :: Integer -> Integer -> Integer -> Integer -> Bool
          solve' s1 s2 i 0 = i == n && s1 == s2
          solve' s1 s2 i a = let r = mod a 10
                                 m = div a 10
                             in if r /= 4 && r /= 7 
                                then False
                                else if i < (div n 2)
                                     then solve' (s1 + r) s2 (i + 1) m
                                     else solve' s1 (s2 + r) (i + 1) m
