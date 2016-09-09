def verbing(s):
	if len(s)>=3:
		if s[-3:] == "ing":
			return s+"ly"
		return s+"ing"
	return s
   
print(verbing("reading"))

def not_bad(s):
	n,b = s.find("not"), s.find("bad")
	if n<b and (n>0 or s[:3]=="not"):
		return s.replace(s[n : b + 3], "good")
	return s
	
print(not_bad("This dinner is not that bad!"))

def front_back(a, b):
	x,y=(len(a)+1)//2, (len(b)+1)//2
	return a[:x]+b[:y]+a[x:]+b[y:]
print(front_back("aaaaa", "bbbb"))