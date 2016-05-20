import Data.List

main :: IO()
main = print . solve . map read . words =<< getContents

data SegmentTree = Empty
                 | Node { lchild :: SegmentTree, rchild :: SegmentTree,
                          left :: Int, right :: Int,
                          maxVal :: (Int, Integer, Int) }

build :: Int -> SegmentTree
build = build' 1
    where build' :: Int -> Int -> SegmentTree
          build' l r | l == r = Node Empty Empty l r (-1, 0, 0)
                     | otherwise = let mid = div (l + r) 2
                                       lc = build' l mid
                                       rc = build' (mid + 1) r
                                   in Node lc rc l r (-1, 0, 0)

update :: Int -> (Int, Integer, Int) -> SegmentTree -> SegmentTree
update pos val = update'
    where update' :: SegmentTree -> SegmentTree
          update' (Node lc rc l r v) | l == r = Node lc rc l r (max v val)
                                     | pos <= div (l + r) 2 = Node (update' lc) rc l r (max v val)
                                     | otherwise = Node lc (update' rc) l r (max v val)

query :: Int -> Int -> SegmentTree -> (Int, Integer, Int)
query ql qr (Node lc rc l r v) | ql == l && qr == r = v
                               | qr <= div (l + r) 2 = query ql qr lc
                               | div (l + r) 2 < ql = query ql qr rc
                               | otherwise = let mid = div (l + r) 2
                                             in max (query ql mid lc) (query (mid + 1) qr rc)

solve :: [Int] -> Integer
solve (n:a) = solve' (n - 1) (reverse a) 0 (update n (n, 0, n) (build n))
    where solve' :: Int -> [Int] -> Integer -> SegmentTree -> Integer
          solve' _ [] s _ = s
          solve' i (a:ax) s t = let (_, d, m) = query (i + 1) a t
                                    val = d - (fromIntegral ((a - m) - n + i))
                                    nt = update i (a, val, i) t
                                    ns = s + val
                                in solve' (i - 1) ax ns nt
