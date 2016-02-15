main :: IO()
main = putStrLn . solve . map read . words =<< getContents

solve :: [Int] -> String
solve [a1, a2, a3, b1, b2, b3, n] = let a = a1 + a2 + a3
                                        b = b1 + b2 + b3
                                        na = div (a + 4) 5
                                        nb = div (b + 9) 10
                                    in if na + nb <= n then "YES" else "NO"
