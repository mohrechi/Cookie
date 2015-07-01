main :: IO()
main = mapM_ print . solve . map read . words =<< getContents

solve :: [Int] -> [Int]
solve (n:a1:a2:b1:b2:c1:c2) = 
    let a = min (n - b1 - c1) a2
        b = min (n - a  - c1) b2
        c = n - a - b
    in [a, b, c]
