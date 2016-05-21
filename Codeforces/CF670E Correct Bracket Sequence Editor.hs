import Data.List
import Data.Functor

main :: IO()
main = do
    [_, _, k] <- map read . words <$> getLine
    brackets <- getLine
    operations <- getLine
    let (left, right) = splitAt (k - 1) brackets
        (remLeft, remRight) = foldl solve (reverse left, right) operations
    putStrLn $ reverse remLeft ++ remRight

solve :: (String, String) -> Char -> (String, String)
solve (l:lx, r) 'L' = (lx, l:r)
solve (l, r:rx) 'R' = (r:l, rx)
solve (l, '(':rx) 'D' = recover (l, remove rx 1)
solve (l, ')':rx) 'D' = recover (remove l (-1), rx)

remove :: String -> Int -> String
remove s 0 = s
remove ('(':sx) sum = remove sx (sum + 1)
remove (')':sx) sum = remove sx (sum - 1)

recover :: (String, String) -> (String, String)
recover (l:lx, []) = (lx, [l])
recover x = x
