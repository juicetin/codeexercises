import System.IO
import Control.Monad

readAInt :: IO [Int]
readAInt = readLn

readABool :: IO Bool
readABool= readLn

-- main = do
-- 	x <- readAInt
-- 	print x

main :: IO [Integer]
main = do
    n <- readLn
    forM [1..2] (const readLn)
