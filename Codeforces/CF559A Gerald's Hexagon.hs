main :: IO()
main = print . solve . map read . words =<< getContents

solve :: [Int] -> Int
solve (a1:a2:a3:a4:a5:a6:_) = 
    let upper = min a2 a6
        lower = min a3 a5
        upperNum = (2*a1 + upper) * upper
        lowerNum = (2*a4 + lower) * lower
        len = 2*a1 + 2 + 2*(upper-1)
        height = abs (a2 - a6)
        midNum = len * height
    in upperNum + midNum + lowerNum
