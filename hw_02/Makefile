CC = g++
CFLAGS = -g -std=c++03 -I include -Wall -O2 -Wextra -Wshadow


all: bin main

bin:
	mkdir -p bin

bin/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp -o bin/main.o

bin/Board.o: src/Board.cpp
	$(CC) $(CFLAGS) -c src/Board.cpp -o bin/Board.o

bin/BoardView.o: src/BoardView.cpp
	$(CC) $(CFLAGS) -c src/BoardView.cpp -o bin/BoardView.o

main: bin/main.o bin/Board.o bin/BoardView.o
	$(CC) $(CFLAGS) bin/main.o bin/Board.o bin/BoardView.o -o main


bin/test.o: test/test.cpp
	$(CC) $(CFLAGS) -c test/test.cpp -o bin/test.o

bin/Test.o: test/Test.cpp
	$(CC) $(CFLAGS) -c test/Test.cpp -o bin/Test.o

tests: bin/test.o bin/Test.o bin/Board.o
	$(CC) $(CFLAGS) bin/test.o bin/Board.o bin/Test.o -o tests


clean:
	rm -rf main bin

val:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./main $(PARAM)

cppcheck:
	cppcheck -I include --enable=all ./

run:
	./main