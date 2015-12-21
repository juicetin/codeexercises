bindList :: [a] -> (a -> [b]) -> [b]
bindList [] _ = []
bindList xs f = concat (map f xs)
