def remove_adjacent(lst):
	i = 0
	while i < len(lst)-1:
		if lst[i] == lst[i + 1]:
			lst=lst[:i]+lst[i+1:]
		else: i += 1
	return lst
print (remove_adjacent([1, 1, 2, 1, 2, 2, 2, 3, 2, 4, 4, 4]))

def linear_merge(lst1, lst2):
	lst3, i ,j = [], 0, len(lst1)>0 and (len(lst1)<len(lst2) and len(lst1) or len(lst2))
	while i<j:
		lst3 += lst1[i]<lst2[i] and [lst1[i]]+[lst2[i]] or [lst2[i]]+[lst1[i]]
		i+=1
	return lst3+lst1[j:]+lst2[j:]
print(linear_merge([1, 2], []))