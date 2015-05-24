import Data.List
main = getContents >>= print . length . group . tail . lines