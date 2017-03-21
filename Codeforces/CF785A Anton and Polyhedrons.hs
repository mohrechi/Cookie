main :: IO ()
main = print . solve . tail . words =<< getContents

solve :: [String] -> Int
solve [] = 0
solve (('T':_):sx) = 4 + solve sx
solve (('C':_):sx) = 6 + solve sx
solve (('O':_):sx) = 8 + solve sx
solve (('D':_):sx) = 12 + solve sx
solve (('I':_):sx) = 20 + solve sx
