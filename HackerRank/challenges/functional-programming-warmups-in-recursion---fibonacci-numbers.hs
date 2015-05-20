module Main where

fib 0 = 0
fib 1 = 1
fib n = fib' 0 1 (n - 3)
    where
        fib' a b 0 = a + b
        fib' a b i = fib' b (a + b) (i - 1)

main = do
    input <- getLine
    print . fib . (read :: String -> Int) $ input
