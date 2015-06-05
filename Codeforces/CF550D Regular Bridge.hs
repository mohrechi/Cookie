data Edge = Edge Int Int
data Graph = Graph [Edge]

instance Show Edge where
    show (Edge a b) = (show a) ++ " " ++ (show b)

instance Show Graph where
    show (Graph [])     = ""
    show (Graph (e:es)) = (show e) ++ "\n" ++ (show (Graph es))
    
main :: IO()
main = putStrLn . solve . read =<< getLine

solve :: Int -> String
solve k | even k    = "NO"
        | k == 1    = "YES\n2 1\n1 2"
        | otherwise = "YES\n" ++ (show (k + k + 4)) ++ " " ++ (show (k * (k + 2))) ++ "\n" ++ (show (genGraph k))
        
genGraph :: Int -> Graph
genGraph k = Graph ([(Edge 1 (k + 3))] ++ (genSub 1 (k + 2)) ++ (genSub (k + 3) (k + k + 4)))

genSub :: Int -> Int -> [Edge]
genSub a b = (genOut (a + 1)) ++ (genIn (a + 2) (a + 1))
    where
        genOut :: Int -> [Edge]
        genOut c | c > b - 2 = []
                 | otherwise  = ((Edge a c):(genOut (c + 1)))
                 
        genIn :: Int -> Int -> [Edge]
        genIn c d | c >= b && d >= b = []
                  | d >= c = genIn (c + 1) (a + 1)
                  | even (c - a) && c == d + 1 && c <= b - 2 = genIn (c + 1) (a + 1)
                  | otherwise = ((Edge d c):(genIn c (d + 1)))