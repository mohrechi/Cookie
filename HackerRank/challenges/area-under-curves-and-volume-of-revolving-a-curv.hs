import Text.Printf (printf)

solve :: Int -> Int -> [Int] -> [Int] -> [Double]
solve l r a b = solve' (fromIntegral l) 0.0 0.0
    where 
        f :: [Int] -> [Int] -> Double -> Double
        f [] [] p = 0.0
        f (ah:at) (bh:bt) p = (fromIntegral ah) * p**(fromIntegral bh) + f at bt p
        solve' :: Double -> Double -> Double -> [Double]
        solve' p s1 s2 = do
            let fv = f a b p
            if p >= (fromIntegral r) then 
                [s1] ++ [s2] 
            else 
                solve' (p + 0.001) (s1 + 0.001 * fv) (s2 + 0.001 * pi * fv * fv)

main :: IO ()
main = getContents >>= mapM_ (printf "%.1f\n"). (\[a, b, [l, r]] -> solve l r a b). map (map read. words). lines
