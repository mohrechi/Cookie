main :: IO()
main = output . solve . tail . words =<< getContents

output :: Bool -> IO()
output True = putStrLn "YES"
output False = putStrLn "NO"

solve :: [String] -> Bool
solve [] = False
solve (s:sa:sb:x) = let a = read sa
                        b = read sb
                    in (a >= 2400 && b > a) || solve x
