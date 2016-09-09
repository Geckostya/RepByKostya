def verbing(s):
	return s  + (len(s)>=3 and (s[-3:] =="ing" and "ly" or "ing") or "")
   
print(verbing("re"))

def not_bad(s):
	n,b = s.find("not"), s.find("bad")
	if n<b:
		return s.replace(s[n : b + 3], "good")

print(not_bad("This dinner is not that bad!"))

def front_back(a, b):
	x,y=(len(a)+1)//2, (len(b)+1)//2
	return a[:x]+b[:y]+a[x:]+b[y:]
print(front_back("aaaaa", "bbbb"))