def remove_adjacent(lst):
	i = 0
	while i < len(lst)-1:
		if lst[i] == lst[i + 1]:
			lst.pop(i)
		else: i += 1
	return lst
print (remove_adjacent([1, 1, 2, 1, 2, 2, 2, 3, 2, 4, 4, 4]))

def linear_merge(lst1, lst2):
	lst3, i ,j = [], 0 ,0
	while 1:
		if lst1[i] < lst2[j]:
			lst3+=[lst1[i]]
			i += 1
		else:
			lst3+=[lst2[i]]
			j += 1
		if i == len(lst1)-1:
			lst3+=lst2[j:]
			break
		if i == len(lst2)-1:
			lst3+=lst1[i:]
			break
	return lst3
print(linear_merge([2, 4, 5, 6], [1, 3, 5, 6, 7, 9]))