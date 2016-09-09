def remove_adjacent(lst):
	lst2 = []
	if len(lst)>0:
		for i in range(0,len(lst)-1):
			if lst[i] != lst[i+1]:
				lst2.append(lst[i])
		if lst[-1] != lst2[-1]:
			lst2.append(lst[-1])
	return lst2
print (remove_adjacent([1,1,2,2,3,5,1,2,8,4,5,5,5,4]))

def linear_merge(lst1, lst2):
	lst3, i, j = [], 0, 0
	while i<len(lst1) and j<len(lst2):
		if lst1[i]<lst2[j]:
			lst3.append(lst1[i])
			i += 1
		else:
			lst3.append(lst2[j])
			j += 1
	return lst3+lst1[i:]+lst2[j:]
print(linear_merge([0,2,18], [0,1,5,8]))