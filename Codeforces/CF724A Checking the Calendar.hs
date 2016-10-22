main :: IO()
main = do
    a <- getLine
    b <- getLine
    output $ any (check (weekToNum a) (weekToNum b)) [0, 2, 3]

weekToNum :: String -> Int
weekToNum "monday" = 0
weekToNum "tuesday" = 1
weekToNum "wednesday" = 2
weekToNum "thursday" = 3
weekToNum "friday" = 4
weekToNum "saturday" = 5
weekToNum "sunday" = 6

check :: Int -> Int -> Int -> Bool
check a b d = (a + d) `mod` 7 == b

output :: Bool -> IO()
output True = putStrLn "YES"
output False = putStrLn "NO"
