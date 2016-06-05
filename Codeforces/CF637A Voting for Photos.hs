import Data.List
import Data.Functor
import Data.Function (on)

main :: IO()
main = do
    _ <- getLine
    a <- words <$> getLine
    let ai = sort $ zip a [1..]
        gai = groupBy ((==) `on` fst) ai
        lai = map (\x -> (negate (length x), (snd (last x), fst (head x)))) gai
        sai = sort lai
    putStrLn $ snd $ snd $ head sai
