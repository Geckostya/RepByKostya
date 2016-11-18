import Prelude hiding (lookup)

-- Реализовать двоичное дерево поиска без балансировки (4 балла)
data BinaryTree k v = Empty | Branch k v (BinaryTree k v) (BinaryTree k v) deriving (Show, Eq)

-- “Ord k =>” требует, чтобы элементы типа k можно было сравнивать 

lookup :: Ord k => k -> BinaryTree k v -> Maybe v
lookup ks Empty = Nothing
lookup ks (Branch k v left right) 
    | ks == k   = Just v
    | ks <= k   = lookup ks left
    | otherwise = lookup ks right 

insert :: Ord k => k -> v -> BinaryTree k v -> BinaryTree k v
insert k v Empty = Branch k v Empty Empty
insert k v (Branch k2 v2 left right)
    | k < k2    = Branch k2 v2 (insert k v left) right
    | k > k2    = Branch k2 v2 left (insert k v right)
    | otherwise = Branch k v left right

delete :: Ord k => k -> BinaryTree k v -> BinaryTree k v
delete ks Empty = Empty
delete ks (Branch k v left right)
    | ks == k   = del left right
    | ks <= k   = Branch k v (delete ks left) right
    | otherwise = Branch k v left (delete ks right)
    where 
        del left Empty = left
        del left right = jointo right left

        jointo (Branch k v Empty right) that = Branch k v that right
        jointo (Branch k v left right) that  = jointo left that

listToTree [] tree     = tree
listToTree (x:xs) tree = (insert x x (listToTree xs tree))