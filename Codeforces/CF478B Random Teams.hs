main :: IO()
main = output . solve . map read . words =<< getContents

solve :: [Integer] -> (Integer, Integer)
solve (n:m:_) = 
    let s = n - (m-1)
        kmax = div (s * (s-1)) 2
        d = div n m
        o = mod n m
        kmin = o * (div (d * (d+1)) 2) + (m-o) * (div (d * (d-1)) 2)
    in (kmin, kmax)

output :: (Integer, Integer) -> IO()
output (a, b) = putStrLn $ (show a) ++ " " ++ (show b)
