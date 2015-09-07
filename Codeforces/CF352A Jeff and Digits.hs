main :: IO()
main = putStrLn . solve . tail . map read . words =<< getContents

solve :: [Int] -> String
solve a =
    let num5 = length $ filter (== 5) a
        num0 = length $ filter (== 0) a
        rnum5 = num5 - (mod num5 9)
    in  if num0 == 0 then "-1" else (if rnum5 == 0 then "0" else (construct rnum5 num0))
    
construct :: Int -> Int -> String
construct 0    0    = ""
construct 0    num0 = '0' : (construct 0 (num0 - 1))
construct num5 num0 = '5' : (construct (num5 - 1) num0)
