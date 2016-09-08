
def verbing(s):
	if len(s)>= 3:
		if s[-3:]!="ing":
			return s+"ing"
		else: return s[:-3]+"ly"
	else: return s		
   
print(verbing("reading"))

def not_bad(s):
	if s.find("not")<s.find("bad"):
		s = s.replace(s[s.find("not") : s.find("bad") + 3], "good")
	return s

print(not_bad("This dinner is not that bad!"))

def front_back(a, b):
	x,y=len(a)//2+len(a)%2, len(b)//2+len(b)%2
	c=a[:x]+b[:y]+a[x:]+b[y:]
	return c
print(front_back("aaaaa", "bbbb"))