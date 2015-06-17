prod [] = 1
prod (x:xs) = x * (prod xs)

main = do
    n <- getLine
    sa <- getLine
    m <- getLine
    sb <- getLine
    print((gcd (prod((map read . words) sa)) (prod((map read . words) sb))) `mod` 1000000007)
