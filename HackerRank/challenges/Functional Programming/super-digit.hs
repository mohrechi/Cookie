import Data.Char

main :: IO()
main = do
   line <- getLine
   let [n, sk] = words line
       k = read sk
       r = mod ((mod (getRoot n) 9) * k) 9
   print $ if r == 0 then 9 else r
    
getRoot :: String -> Int
getRoot ""    = 0
getRoot (s:ss) = ord(s) - ord('0') + (getRoot ss)
