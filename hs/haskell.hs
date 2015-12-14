square x = x * x
doubleMe x = x + x
lucky :: (Integral a) => a -> String
lucky 7 = "Yay"
lucky x = "Sorry"

mymax :: (Ord a) => [a] -> a
mymax [x] = x
mymax (x:xs) = let maxTail = mymax xs in (if x < maxTail then maxTail else x)

mymax' :: (Ord a) => [a] -> a
mymax' xs
    | [x] <- xs = x
    | (x:xs) <- xs = let y = mymax xs in (if x < y then y else x)

myelem :: (Eq a) => a -> [a] -> Bool
myelem a [] = False
myelem a (x:xs) = a == x || myelem a xs

chain :: (Integral a) => a -> [a]
chain 1 = [1]
chain x
    | odd x = x:chain (3*x+1)
    | even x = x:chain (x `div` 2)

mysum :: (Num a) => [a] -> a
mysum = foldl (+) 0
