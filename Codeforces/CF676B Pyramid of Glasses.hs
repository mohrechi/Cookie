import qualified Data.Map as Map

main :: IO()
main = print . solve . map read . words =<< getLine

data Queue a = Queue { 
  inbox :: [a], 
  outbox :: [a] 
} deriving (Eq, Show)

initQueue :: Queue a
initQueue = Queue [] []

push :: a -> Queue a -> Queue a
push e (Queue inb out) = Queue (e:inb) out

pop :: Queue a -> (a, Queue a)
pop q@(Queue inb []) = pop $ Queue [] (reverse inb)
pop (Queue inb outb) = (head outb, Queue inb (tail outb))

isEmptyQueue :: Queue a -> Bool
isEmptyQueue (Queue inbox outbox) = null inbox && null outbox

initMap :: Int -> Map.Map (Int, Int) Double
initMap n = Map.fromList [((i, j), 0.0) | i <- [1..n], j <- [1..i]]

removeMaybe :: Maybe Double -> Double
removeMaybe (Just x) = x

tryPush :: Int -> (Int, Int) -> Queue (Int, Int) -> Queue (Int, Int)
tryPush n p@(i, j) q | i > n || j > i = q
                     | otherwise = push p q

tryAdjust :: (Double -> Double) -> (Int, Int) -> Map.Map (Int, Int) Double -> Map.Map (Int, Int) Double
tryAdjust f (i, j) m | Map.member (i, j) m = Map.adjust f (i, j) m
                     | otherwise = m

solve :: [Int] -> Int
solve [n, t] = Map.size $ Map.filter (== 1.0) $ dumping (initMap n) t
    where dumping :: Map.Map (Int, Int) Double -> Int -> Map.Map (Int, Int) Double
          dumping m 0 = m
          dumping m t = let nextMap = Map.adjust (+ 1.0) (1, 1) m
                            nextQueue = push (1, 1) initQueue
                        in dumping (flow nextQueue nextMap) (t - 1)

          flow :: Queue (Int, Int) -> Map.Map (Int, Int) Double -> Map.Map (Int, Int) Double
          flow q m | isEmptyQueue q = m
                   | otherwise = let ((i, j), nextQueue) = pop q
                                     volumn = removeMaybe $ Map.lookup (i, j) m
                                     halfVol = (volumn - 1.0) * 0.5
                                 in if volumn > 1.0
                                    then let nextMap1 = Map.adjust (const 1.0) (i, j) m
                                             nextMap2 = tryAdjust (+ halfVol) (i + 1, j) nextMap1
                                             nextMap3 = tryAdjust (+ halfVol) (i + 1, j + 1) nextMap2
                                             nextQueue1 = tryPush n (i + 1, j) nextQueue
                                             nextQueue2 = tryPush n (i + 1, j + 1) nextQueue1
                                         in flow nextQueue2 nextMap3
                                    else flow nextQueue m
