--maximum' :: (Ord a) => [a] -> a
--maximum' [] = error "maximum of empty list"
--maximum' [x] = x
--maximum' (x:xs) = max x (maximum' xs)
    -- | x > maxTail = x
    -- | otherwise = maxTail
    -- where maxTail = maximum' xs

maximum' :: (Ord a) => [a] -> a
maximum' xs = case xs of [] -> error "maximum of empty list"
                         [x] -> x
                         (x:xs) -> max x (maximum' xs)
