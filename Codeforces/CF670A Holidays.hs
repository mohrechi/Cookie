main :: IO()
main = putStrLn . unwords . map show . solve . read =<< getLine

solve :: Int -> [Int]
solve n = let common = div n 7 * 2
          in [common + max 0 (mod n 7 - 5), common + min 2 (mod n 7)]
