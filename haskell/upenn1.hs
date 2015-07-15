-- Exercise 1
toDigits :: Integer -> [Integer]
toDigits n
    | n <= 0 = []
    | n < 10 = [n]
    | otherwise = toDigits (div n 10) ++ [mod n 10]

toDigitsRev :: Integer -> [Integer]
toDigitsRev x = reverse (toDigits x)

-- Exercise 2
doubleFromLeft :: [Integer] -> [Integer]
-- doubleFromLeft xs
--     | length xs <= 1 = xs
-- doubleFromLeft [x,xs]   = [x, 2*xs]
doubleFromLeft [x,y]    = [x, 2*y]
doubleFromLeft (x:y:xs) = x : 2*y : doubleFromLeft xs

doubleEveryOther :: [Integer] -> [Integer]
doubleEveryOther lst = reverse (doubleFromLeft (reverse lst))

-- Exercise 3
sumDigits :: [Integer] -> Integer
sumDigits xs
    | length xs == 0 = 0
sumDigits (x:xs) = sum (toDigits x) + sumDigits xs

-- Exercise 4
validate :: Integer -> Bool
validate xs = sumDigits ( doubleEveryOther ( toDigits xs )) `mod` 10 == 0

-- Exercise 5 - The Towers of Hanoi

