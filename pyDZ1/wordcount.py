import sys
 
def read_words(filename):
	words = []
	with open(filename, "r") as f:
		for line in f:
			words.extend(line.lower().split())
	return words

def make_dict(words):
	dct=dict()
	for wrd in words:
		if wrd in dct:
			dct[wrd] +=1
		else: dct[wrd] = 1
	return dct

def print_words(filename):
	dct = make_dict(read_words(filename))
	sortedKeys = sorted(dct.keys())
	for key in sortedKeys:
		print(key, dct[key])
		
import operator
def print_top(filename):
	dct = make_dict(read_words(filename))
	sortedDct = sorted(dct.items(), key=operator.itemgetter(1), reverse=True)
	for value in (sortedDct[:20]):
		print(value[0],value[1])

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