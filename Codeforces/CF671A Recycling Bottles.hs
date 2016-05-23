import Data.List
import Data.Functor

main :: IO()
main = do
    [ax, ay, bx, by, tx, ty] <- map read . words <$> getLine
    n <- read <$> getLine
    d <- split . map read . words <$> getContents
    let ad = map (dist (ax, ay)) d
        bd = map (dist (bx, by)) d
        td = map (dist (tx, ty)) d
        total = 2 * sum td
        af = [x - y | (x, y) <- zip ad td]
        bf = [x - y | (x, y) <- zip bd td]
        asd = sort $ zip af [0..]
        bsd = sort $ zip bf [0..]
        minA = fst $ head asd
        minB = fst $ head bsd
        minAB = min2 n asd bsd
        minBA = min2 n bsd asd
    print $ total + minimum [minA, minB, minAB, minBA]

split :: [a] -> [(a, a)]
split [] = []
split (x:y:s) = (x, y) : split s

square :: Double -> Double
square x = x * x

dist :: (Double, Double) -> (Double, Double) -> Double
dist (x1, y1) (x2, y2) = sqrt (square (x1 - x2) + square (y1 - y2))

min2 :: Int -> [(Double, Int)] -> [(Double, Int)] -> Double
min2 n a b | n == 1 = fst $ head a
           | snd (head a) == snd (head b) = fst (head a) + fst (head $ tail b)
           | otherwise = fst (head a) + fst (head b)
