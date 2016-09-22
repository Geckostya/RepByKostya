import os, sys
import hashlib
 
def findDup(parent):
    dups = {}
    for dirName, subdirs, fileList in os.walk(parent):
        for filename in fileList:
            path = os.path.join(dirName, filename)
            hash = hashfile(path)
            if hash in dups:
                dups[hash].append(path)
            else:
                dups[hash] = [path]
    return dups
 
 
def hashfile(path):
    file = open(path, 'rb')
    hasher = hashlib.md5()
    buf = file.read(4096)
    while len(buf) > 0:
        hasher.update(buf)
        buf = file.read(4096)
    file.close()
    return hasher.hexdigest()
 
if len(sys.argv) > 1:
    dups = {}
    i = sys.argv[1]
    leng = len(i)+1
    if os.path.exists(i):
        # Find the dups
        dups = findDup(i)
    #print
    results = list(filter( lambda x: len(x) > 1, dups.values()))
    for result in results:
        for subresult in result:
            print(subresult[leng:], end = ":")
        print()
else:
    print('Usage: python dupFinder.py folder or python dupFinder.py folder1 folder2 folder3')