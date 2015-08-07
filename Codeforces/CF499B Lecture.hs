import Data.Map

main :: IO()
main = putStrLn . solve . words =<< getContents

solve :: [String] -> String
solve (_:sm:strs) =
    let m = read sm
        (words, sentence) = splitAt (m*2) strs
        wordMap = getMap words Data.Map.empty
    in  unwords (trans sentence wordMap)
    
getMap :: [String] -> Map String String -> Map String String
getMap []       wordMap = wordMap
getMap (a:b:ss) wordMap | (length a) <= (length b) = getMap ss (insert b a (insert a a wordMap))
                        | otherwise                = getMap ss (insert a b (insert b b wordMap))

trans :: [String] -> Map String String -> [String]
trans []     _       = []
trans (s:ss) wordMap = (removeMaybe (Data.Map.lookup s wordMap)):(trans ss wordMap)

removeMaybe :: Maybe a -> a
removeMaybe (Just a) = a
