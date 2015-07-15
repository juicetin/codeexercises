calcBmis :: (RealFloat a) => [(a, a)] -> [a]
calcBmis xs = [bmi | (w, h) <- xs, let bmi = w / h ^ 2]
--calcBmis xs = [bmi w h | (w, h) <- xs]
--    where bmi w h = w / h ^ 2
