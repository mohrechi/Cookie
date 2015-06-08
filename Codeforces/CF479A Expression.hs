main :: IO()
main = print . solve . map read . lines =<< getContents

solve :: [Int] -> Int
solve [a,b,c] = maximum [a*b*c, a+b+c, a*(b+c), (a+b)*c]