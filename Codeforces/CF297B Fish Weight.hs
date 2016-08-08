import Data.List
import Data.Maybe (fromJust)
import Data.ByteString (ByteString)
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C

main :: IO()
main = output . solve . map (fst . fromJust . C.readInt) . C.words =<< B.getContents

output :: Bool -> IO()
output True = putStrLn "YES"
output False = putStrLn "NO"

solve :: [Int] -> Bool
solve (n:_:k:s) = let (a, b) = splitAt n s
                      sa = reverse $ sort a
                      sb = reverse $ sort b
                  in solve' k sa sb 0 0
                  where solve' :: Int -> [Int] -> [Int] -> Int -> Int -> Bool
                        solve' 0 _ _ _ _ = False
                        solve' k [] [] na nb = na > nb
                        solve' k (a:sa) [] na nb = na + length (a:sa) > nb
                        solve' k [] (b:sb) na nb | k == b = solve' k [] sb na (nb + 1)
                                                 | otherwise = na > nb
                        solve' k (a:sa) (b:sb) na nb | k == a = solve' k sa (b:sb) (na + 1) nb
                                                     | k == b = solve' k (a:sa) sb na (nb + 1)
                                                     | na > nb = True
                                                     | otherwise = solve' (min (k - 1) (max a b)) (a:sa) (b:sb) na nb
