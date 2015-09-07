main :: IO()
main = print . solve . tail . map read . words =<< getContents

solve :: [Integer] -> Integer
solve h = solve' h 0 0
    where
        solve' :: [Integer] -> Integer -> Integer -> Integer
        solve' []     _     _      = 0
        solve' (h:hs) lastH energy | energy + lastH - h < 0 = h - energy - lastH + (solve' hs h 0)
                                   | otherwise              = solve' hs h (energy + lastH - h)
