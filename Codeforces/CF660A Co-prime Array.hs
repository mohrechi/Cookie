import Data.Functor

main :: IO()
main = do
    n <- read <$> getLine
    a <- map read . words <$> getLine
    let b = solve a
    print $ (length b) - n
    putStrLn $ unwords $ map show b

solve :: [Int] -> [Int]
solve [] = []
solve [a] = [a]
solve (a:b:s) | gcd a b > 1 = a:1:solve (b:s)
              | otherwise = a:solve (b:s)

