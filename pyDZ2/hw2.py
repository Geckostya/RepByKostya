import os, sys
import hashlib

def findDup(parent):
	dups = {}
	for dirName, subdirs, fileList in os.walk(parent):
		for filename in fileList:
			if filename[0]!='.' and filename[0]!='~':
				path = os.path.join(dirName, filename)
				hash = hashfile(path)
				if hash in dups:
					dups[hash].append(path[leng:])
				else:
					dups[hash] = [path[leng:]]
	return dups

def hashfile(path):
	digest = hashlib.md5()
	with open(path, "rb") as f:
		buf = f.read(1024)
		while len(buf)>0:
			digest.update(buf)
			buf = f.read(1024)
	return digest.hexdigest()
def printResult(dupsDict):
	results = list(filter( lambda x: len(x) > 1, dupsDict.values()))
	for result in results:
		print(":".join(result))
if len(sys.argv) > 1:
	dups = {}
	i = sys.argv[1]
	leng = len(i)+1
	if os.path.exists(i):
		dups = findDup(i)
		printResult(dups);	
else:
	print('wrong format')