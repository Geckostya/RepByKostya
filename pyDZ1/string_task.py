# Given a string, if its length is at least 3,
# add 'ing' to its end.
# Unless it already ends in 'ing', in which case
# add 'ly' instead.
# If the string length is less than 3, leave it unchanged.
# Return the resulting string.
#
# Example input: 'read'
# Example output: 'reading'
def verbing(s):
    if len(s)>= 3:
        if s[-3:]!="ing":
            s+="ing"
        else: s=s[:-3]+"ly"    
    return s
print(verbing("reading"))
# Given a string, find the first appearance of the
# substring 'not' and 'bad'. If the 'bad' follows
# the 'not', replace the whole 'not'...'bad' substring
# with 'good'.
# Return the resulting string.
#
# Example input: 'This dinner is not that bad!'
# Example output: 'This dinner is good!'
def not_bad(s):
    catched = 0
    for i in range(0,len(s)-3):
        if s[i:i+3]=="not":
            catched = 1
            start = i
        if s[i:i+3]=="bad" and catched:
            s=s[:start]+"good"+s[i+3:]
            catched = 0
    return s
print(not_bad("This dinner is not that bad! Yeah, thats really not bad."))

# Consider dividing a string into two halves.
# If the length is even, the front and back halves are the same length.
# If the length is odd, we'll say that the extra char goes in the front half.
# e.g. 'abcde', the front half is 'abc', the back half 'de'.
#
# Given 2 strings, a and b, return a string of the form
#  a-front + b-front + a-back + b-back
#
# Example input: 'abcd', 'xy'
# Example output: 'abxcdy'
def front_back(a, b):
    x,y=len(a),len(b)
    c=a[:x//2+x%2]+b[:y//2+y%2]+a[x//2+x%2:]+b[y//2+y%2:]
    return c
print(front_back("aaaaa", "bbbb"))
