import Data.List

main :: IO()
main = printBool . solve . lines =<< getContents

printBool :: Bool -> IO()
printBool b = putStrLn (if b then "YES" else "NO")

solve :: [String] -> Bool
solve (a:b:_) | (length a) /= (length b) = False
              | otherwise = let (da:db:_) = get_diff a b [[], []]
                            in (length da) == 2 && (sort da) == (sort db)

get_diff :: String -> String -> [[Char]] -> [[Char]]
get_diff []     []     d          = d
get_diff (a:ax) (b:bx) (da:db:dx) | a == b = get_diff ax bx (da:db:dx)
                                  | otherwise = get_diff ax bx ((a:da):(b:db):dx)
