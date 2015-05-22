solve :: [Int] -> Int
solve [a, b] | a < b = a
             | otherwise = b + solve [a - b + 1, b]

main :: IO()
main = getLine >>=
    print . solve . map read . words