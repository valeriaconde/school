module Valesauria where

-- fibonacci (indexado en 0)
-- wuwuw si jala
fibonacci :: Integer -> Integer
fibonacci 0 = 1
fibonacci 1 = 1
fibonacci n = fibonacci(n-1) + fibonacci (n-2)

-- evenNumbers
evenNumbers :: [Integer] -> [Integer]
evenNumbers [] = []
evenNumbers lst = [x | x <- lst, mod x 2 == 0]

-- listor
listor :: [Integer] -> [Integer] -> [Integer]
listor [] [] = []
listor (x:xs) (y:ys) = if x + y > 0
  then 1 : listor xs ys
  else 0 : listor xs ys
  
--inverseRelation
inverseRelation :: [(Integer, Integer)] -> [(Integer, Integer)]
inverseRelation [] = []
inverseRelation (x:xs) = (snd(x), fst(x)) : inverseRelation xs

--multiples
multiples :: [Integer] -> Integer -> [Integer]
multiples [] _ = []
multiples lst y = [x | x <- lst, mod x y == 0]

-- toBinaryString
toBinaryString :: Integer -> [Char]
toBinaryString 0 = []
toBinaryString n = if mod n 2 == 0
  then toBinaryString (n `div` 2) ++ ['0']
  else toBinaryString (n `div` 2) ++ ['1']

--polinomios
evaluatePol :: [Integer] -> Integer -> Integer
evaluatePol [] _ = 0
evaluatePol (x:xs) y = (x * (y^length(xs))) + evaluatePol xs y



main :: IO()
--main = print (fibonacci 5)
--main = print (evenNumbers([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
--main = print (listor [1,0,1,0,1,0] [1,0,0,0,1,1])
--main = print(inverseRelation [(1, 2), (4, 5), (8, 4)])
--main = print (multiples [1,2,3,4,5,6,7,8,9] 3)
--main = print (toBinaryString 4)
--main = print (evaluatePol [4, 2, 3] 5)