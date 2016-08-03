import Data.List

main :: IO()
main = output . solve . lines =<< getContents

output :: Bool -> IO()
output True = putStrLn "OK"
output False = putStrLn "WRONG_ANSWER"

solve :: [String] -> Bool
solve [num, actual] = let sorted = sort $ filter ('0' /=) num
                          zeros = filter ('0' ==) num
                          (first, rest) = splitAt 1 sorted
                          expect = first ++ zeros ++ rest
                      in expect == actual
