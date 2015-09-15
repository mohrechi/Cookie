import qualified Data.List as L
import qualified Data.Set as S

main :: IO()
main = output . solve . L.map read . words =<< getContents

solve :: [Int] -> Bool
solve (n:m:a) = solve' a S.empty
    where
        solve' :: [Int] -> (S.Set Int) -> Bool
        solve' _      s | S.member 0 s = True
        solve' []     _ = False
        solve' (a:ax) s = let si = S.singleton (mod a m)
                              sn = S.map (\x -> mod (x + a) m) s
                              ssi = S.union s si
                              sin = S.union ssi sn
                          in  solve' ax sin

output :: Bool -> IO()
output True  = putStrLn "YES"
output False = putStrLn "NO"
