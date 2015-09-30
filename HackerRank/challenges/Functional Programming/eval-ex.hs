solve :: Double -> Double
solve x = solve' 1.0 1.0 0.0 1
    where
        solve' :: Double -> Double -> Double -> Int -> Double
        solve' sx f s 11 = s
        solve' sx f s i = solve' (sx*x) (f*(fromIntegral i)) (s + sx/f) (i+1)

main :: IO ()
main = getContents >>= mapM_ print. map solve. map (read::String->Double). tail. words
