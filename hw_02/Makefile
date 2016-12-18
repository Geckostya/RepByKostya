CC = g++
CFLAGS = -g -std=c++03 -I include -Wall -O0 -Wextra -Wshadow


all: bin main

bin:
	mkdir -p bin

bin/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp -o bin/main.o

bin/Board.o: src/Board.cpp
	$(CC) $(CFLAGS) -c src/Board.cpp -o bin/Board.o

bin/BoardView.o: src/BoardView.cpp
	$(CC) $(CFLAGS) -c src/BoardView.cpp -o bin/BoardView.o

bin/NcursesBoardView.o: src/NcursesBoardView.cpp
	$(CC) $(CFLAGS) -c src/NcursesBoardView.cpp -o bin/NcursesBoardView.o


main: bin/main.o bin/Board.o bin/BoardView.o bin/NcursesBoardView.o
	$(CC) $(CFLAGS) bin/main.o bin/Board.o bin/BoardView.o bin/NcursesBoardView.o -o main -lncurses


bin/test.o: tests/test.cpp
	$(CC) $(CFLAGS) -c tests/test.cpp -o bin/test.o

bin/TestClass.o: tests/TestClass.cpp
	$(CC) $(CFLAGS) -c tests/TestClass.cpp -o bin/TestClass.o

bin/BoardTest.o: tests/BoardTest.cpp
	$(CC) $(CFLAGS) -c tests/BoardTest.cpp -o bin/BoardTest.o

test: bin/test.o bin/TestClass.o bin/Board.o bin/BoardTest.o
	$(CC) $(CFLAGS) bin/test.o bin/Board.o bin/TestClass.o bin/BoardTest.o -o test


clean:
	rm -rf main bin test saved_game

val:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./main $(PARAM)

cppcheck:
	cppcheck -I include --enable=all ./

run:
	./main