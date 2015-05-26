import Data.Char

main :: IO()
main = getContents >>= mapM_ (putStrLn . solve) . tail . lines

is_digit :: Char -> Bool
is_digit c = (ord '0') <= (ord c) && (ord c) <= (ord '9')

is_rxcy :: String -> Bool
is_rxcy (x:y:xs) | (is_digit x) && (not (is_digit y)) = True
                 | otherwise = is_rxcy (y:xs)
is_rxcy s = False

solve :: String -> String
solve s | is_rxcy(s) = conv1 s
        | otherwise = conv2 s
        
get_first_digit :: String -> String
get_first_digit (x:xs) | is_digit x = (x:xs)
                       | otherwise = get_first_digit xs
        
get_first_non_digit :: String -> String
get_first_non_digit (x:xs) | is_digit x = get_first_non_digit xs
                           | otherwise = xs
        
read_num :: String -> Int
read_num s = read_num' s 0
    where
        read_num' :: String -> Int -> Int
        read_num' "" num = num
        read_num' (x:xs) num | is_digit x = read_num' xs (num * 10 + (ord x) - (ord '0'))
                             | otherwise = num
        
conv1 :: String -> String        
conv1 (x:xs) =
    let row = read_num(xs)
        col = read_num(get_first_non_digit(xs))
    in  (num2alpha col) ++ (show row)
    
num2alpha :: Int -> String
num2alpha 0 = ""
num2alpha num = (num2alpha (div (num - 1) 26)) ++ [(chr ((rem (num - 1) 26) + ord('A')))]

conv2 :: String -> String        
conv2 s = 
    let col = read_alpha(s)
        row = read_num(get_first_digit(s))
    in "R" ++ (show row) ++ "C" ++ (show col)

read_alpha :: String -> Int
read_alpha s = read_alpha' s 0
    where
        read_alpha' "" num = num
        read_alpha' (x:xs) num | is_digit x = num
                               | otherwise = read_alpha' xs (num * 26 + (ord(x) - ord('A') + 1))