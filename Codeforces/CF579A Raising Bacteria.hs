main = print . solve . read =<< getLine
solve 0 = 0
solve x = (mod x 2) + solve (div x 2)
