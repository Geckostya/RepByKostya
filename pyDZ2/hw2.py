import os, sys
import hashlib
from collections import defaultdict

def findDup(parent):
	dups = defaultdict(list)
	for dirName, subdirs, fileList in os.walk(parent):
		for filename in fileList:
			if filename[0]!='.' and filename[0]!='~':
				path = os.path.join(dirName, filename)
				path = os.path.abspath(path)
				if not os.path.islink(path):
					hash = hashfile(path)
					dups[hash].append(path)
	return dups

def hashfile(path):
	digest = hashlib.md5()
	with open(path, "rb") as f:
		buf = f.read(1024)
		while len(buf)>0:
			digest.update(buf)
			buf = f.read(1024)
	return digest.hexdigest()
	
def printResult(dups):
	for result in dups:
		if len(dups[result])>1:
			print(":".join(dups[result]))
		
if len(sys.argv) > 1:
	dups = {}
	i = sys.argv[1]
	if os.path.exists(i):
		printResult(findDup(i));	
else:
	print('wrong format')