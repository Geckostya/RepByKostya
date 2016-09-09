def remove_adjacent(lst):
	i,lst2 = 0, []
	while i < len(lst)-1:
		if lst[i] != lst[i + 1]:
			lst2+=[lst[i]]
		i+=1;
	if lst[-1] != lst2[-1]:
		lst2+=[lst[-1]]
	return lst2
print (remove_adjacent([1, 1, 2, 1, 2, 2, 2, 3, 2, 4, 4, 5]))

def linear_merge(lst1, lst2):
	lst3, i, j = [], 0, 0
	while i<len(lst1) and j<len(lst2):
		if lst1[i]<lst2[j]:
			lst3 += [lst1[i]]
			i+=1
		else:
			lst3 += [lst2[j]]
			j+=1
	return lst3+lst1[i:]+lst2[j:]
print(linear_merge([0,2,18], [0,1,5,8]))