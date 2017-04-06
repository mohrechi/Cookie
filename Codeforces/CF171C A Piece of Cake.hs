main :: IO ()
main = do
    s <- getLine
    let a = map read $ tail $ words s :: [Integer]
    print $ sum $ map (uncurry (*)) $ zip a [1..]
