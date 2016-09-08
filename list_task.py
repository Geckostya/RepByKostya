# Remove equal adjacent elements
#
# Example input: [1, 2, 2, 3]
# Example output: [1, 2, 3]
def remove_adjacent(lst):
    lst2 = []
    for i in range(1,len(lst)):
        if lst[i]!=lst[i-1]:
            lst2 += [lst[i-1]]
    if lst[-1]==lst[-2]:
            lst2 += [lst[-1]]
    return lst2
print (remove_adjacent([1, 1, 2, 1, 2, 2, 2, 3, 2, 4, 4, 4]))
# Merge two sorted lists in one sorted list in linear time
#
# Example input: [2, 4, 6], [1, 3, 5]
# Example output: [1, 2, 3, 4, 5, 6]
def linear_merge(lst1, lst2):
    lst3=[]
    for i in range(0, max(len(lst1), len(lst2))):
        x,y = lst1[i:i+1], lst2[i:i+1]
        if x and y:
            lst3+=min(x, y) 
            lst3+= max(x, y)#Эти ф-ции не делают конечное время больше линейного?        else:
            lst3+= x or y
    return lst3
print(linear_merge([2, 4, 5, 6], [1, 3, 5, 6, 7, 7, 8]))

