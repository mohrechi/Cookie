import Data.List
import Debug.Trace

main :: IO()
main = print . solve . map read . words =<< getLine

type Perm = [Int]

perm :: [Perm]
perm = genPerm 0 [] []
    where genPerm :: Int -> [Int] -> [[Int]] -> [[Int]]
          genPerm d s p | length s == 6 = s:p
                        | d == 10 = p
                        | otherwise = genPerm (d + 1) s $ genPerm (d + 1) (d:s) p

toDigits :: Int -> Int -> [Int]
toDigits _ 0 = []
toDigits a i = mod a 10 : toDigits (div a 10) (i - 1)

toLower :: [Int] -> [Int]
toLower [] = []
toLower (a:ax) | a == 9 = 6 : toLower ax
               | otherwise = a : toLower ax 

valid :: [[[Int]]] -> Int -> [Perm] -> Bool
valid [] _ _ = True
valid (n:nx) m px = validD n px
    where validD :: [[Int]] -> [Perm] -> Bool
          validD d p = any (validP p) d && valid nx m px

          validP :: [Perm] -> [Int] -> Bool
          validP _ [] = True
          validP (p:ps) (d:ds) = d `elem` p && validP ps ds

pick :: Int -> [Perm] -> [[Perm]]
pick n p = pick' n p [] []
    where pick' :: Int -> [Perm] -> [Perm] -> [[Perm]] -> [[Perm]]
          pick' 0 _ s r = s:r
          pick' n [] s r = r
          pick' n (p:px) s r = pick' n px s $ pick' (n - 1) (p:px) (p:s) r

solve :: [Int] -> Int
solve [n, m] = let d = map (\x -> permutations $ toLower $ toDigits (x * x) m) [1..n]
               in length $ filter (valid d m) $ pick m $ map toLower perm
