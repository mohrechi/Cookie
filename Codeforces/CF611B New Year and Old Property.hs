main :: IO()
main = print . solve (initValids [1] [] 0) . map read . words =<< getLine

initValids :: [Integer] -> [Integer] -> Int -> [Integer]
initValids ones zeros 64 = []
initValids ones zeros i  = zeros ++ initValids (map (\x -> x * 2 + 1) ones)
                                    ((map (\x -> x * 2) ones) ++ (map (\x -> x * 2 + 1) zeros))
                                    (i + 1)

solve :: [Integer] -> [Integer] -> Int
solve [] _ = 0
solve (v:vs) [a, b] | a <= v && v <= b = 1 + solve vs [a, b]
                    | otherwise = solve vs [a, b]
