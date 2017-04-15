import Data.List

main :: IO ()
main = do
    d <- readLn
    let (a, h) = snd $ minimum [(abs (f (fromIntegral a) (fromIntegral h) - d), (a, h)) | a <- [1..10], h <- [1..10]]
    putStrLn $ show a ++ " " ++ show h

f :: Double -> Double -> Double
f a h = (a * h) / 2 / sqrt (a^2 / 4 + h^2)
