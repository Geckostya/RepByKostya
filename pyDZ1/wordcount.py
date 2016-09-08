import sys

def fread(fname):
    file = open(fname)
    dct=dict()
    allwords = []
    for line in file:
        line.strip()
        line = line.lower()
        allwords.extend(line.split())
    for wrd in allwords:
        if wrd in dct:
            dct[wrd] +=1
        else: dct[wrd] = 1
    return dct

#sprint(fread("blabla.txt"))



def print_words(fname):
    dct = fread(fname)
    sortedKeys = sorted(dct.keys())
    for key in sortedKeys:
        print(key, dct[key])
import operator
def print_top(fname):
    dct = fread(fname)
    #for k,v in dct.items()
    sortedDct = sorted(dct.items(), key=operator.itemgetter(1))
    j=0
    for i in reversed(sortedDct):
        j+=1
        print(i[0],i[1])
        if j==20: break
    

#print_words("blabla.txt")


def main():
    if len(sys.argv) != 3:
        print('usage: ./wordcount.py {--count | --topcount} file')
        sys.exit(1)

    option = sys.argv[1]
    filename = sys.argv[2]
    if option == '--count':
        print_words(filename)
    elif option == '--topcount':
        print_top(filename)
    else:
        print('unknown option: ' + option)
        sys.exit(1)

if __name__ == '__main__':
    main()
