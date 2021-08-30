module Valesauria where
import Data.List

--unique
countChar :: [Char] -> Char -> Integer
countChar [] _ = 0
countChar (x:xs) y = if x == y
  then 1 + countChar xs y
  else countChar xs y

unique :: [Char] -> [Char]
unique [] = []
unique lst = [x | x <- lst, countChar lst x == 1]

--evenNumbers
evenHigherNumbers :: [Integer] -> [Integer]
evenHigherNumbers [] = []
evenHigherNumbers lst = [x | x <- lst, mod x 2 == 0]

--reduceMatrix
sumArr :: [Integer] -> Integer
sumArr [] = 0
sumArr (x:xs) = x + sumArr xs

reduceMatrix :: [[Integer]] -> Integer
reduceMatrix [] = 0
reduceMatrix mat = sum (map sumArr mat)

--maskedSum
maskedSum :: [Integer] -> [Bool] -> Integer
maskedSum [] _ = 0
maskedSum _ [] = 0
maskedSum v w = sum (map (\(x, y) -> if y then x else 0) (zip v w))

--multiples
multiples :: [Integer] -> Integer -> [Integer]
multiples [] _ = []
multiples lst y = [x | x <- lst, mod x y == 0]

--combine
combine :: [[a]] -> [[a]] -> [[(a,a)]]
combine [] _ = []
combine _ [] = []
combine (x:xs) (y:ys) = zip x y : combine xs ys

--rotate matrix
-- jeje
rotHelp :: [[x]] -> [[x]]
rotHelp = transpose . map reverse

rotate :: [[x]] -> [[x]]
rotate mat = rotHelp (rotHelp (rotHelp mat))

main :: IO()
--main = print (unique ['a', 'b', 'a', 'c'])
--main = print (evenHigherNumbers [1,2,3,4,5,6])
--main = print (reduceMatrix [[1,2,3,4],[1,2,3,4]])
--main = print (maskedSum [1, 2, 3, 4, 5, 6] [True, False, False, True, False, True])
--main = print (multiples [1,2,3,4,5,6,7,8,9] 3)
--main = print (combine [[1,2],[3,4]] [[5,6],[7,8]])
main = print (rotate [[1,2,3],[4,5,6],[7,8,9]])