main :: IO ()
main = do
    s <- getLine
    let a = map read $ tail $ words s :: [Integer]
    print $ sum $ map (\x -> fst x * snd x) $ zip a [1..]
