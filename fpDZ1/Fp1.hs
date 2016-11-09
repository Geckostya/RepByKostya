
head' :: [a] -> a
head' [] = error "empty list"
head' (x:xs) = x

tail' :: [a] -> [a]
tail' [] = [] 
tail' (x:xs) = xs

len' :: Num a => [b] -> a
len' [] = 0
len' (x:xs) = len' xs + 1 

take' :: Int -> [a] -> [a]
take' a [] = []
take' a (x:xs) = if a>0 then x : take' (a-1) xs else []

drop' :: Int -> [a] -> [a]
drop' a [] = []
drop' a (x:xs) = if a>0 then drop' (a-1) xs else x:xs

filter' :: (a -> Bool) -> [a] -> [a]
filter' f [] = []
filter' f (x:xs) = if f x == True then x:filter' f xs  else filter' f xs

foldl' :: (a -> b -> a) -> a -> [b] -> a
foldl' f z [] = z
foldl' f z (x:xs) = foldl' f (f z x) xs

concat' :: [a] -> [a] -> [a]
concat' [] [] = []
concat' [] (y:ys) = y : concat' [] ys 
concat' (x:xs) ys = x: concat' xs ys

quickSort' :: Ord a => [a] -> [a]
quickSort' [] = []
quickSort' xs = concat' ( concat' (part' (< x) xs) (filter' (== x) xs)) (part' (>x) xs)
    where part' f ys = quickSort' (filter' f ys) 
          x = head' (drop' (div (len' xs) 2) xs)