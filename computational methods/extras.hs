module danyYvale where
--profundidad
data Arbol a = X a
             | Y a (Arbol a) (Arbol a)
             deriving (Show, Eq)


profundidad :: Arbol a -> Int
profundidad (X _)     = 0
profundidad (Y _ a b) = 1 + max (profundidad a) (profundidad b)

--mayor
maxDegree :: (Hashable v, Eq v) => g v e -> Int
    maxDegree = maximum . degrees
