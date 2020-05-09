POSTFIX = o
FLAG = -pedantic-errors -std=c++11

main: main.o game.o help.o mode.o snake.o map.o beam.o
	g++ $^ -o $@
main.o: main.cpp game.h help.h mode.h
	g++ -c main.cpp $(FLAG)
game.o: game.cpp game.h snake.h beam.h map.h
	g++ -c game.cpp $(FLAG)
help.o: help.cpp help.h
	g++ -c help.cpp $(FLAG)
mode.o: mode.cpp mode.h game.h
	g++ -c mode.cpp $(FLAG)
snake.o: snake.cpp snake.h
	g++ -c snake.cpp $(FLAG) 
map.o: map.cpp map.h
	g++ -c map.cpp $(FLAG)
beam.o: beam.cpp beam.h
	g++ -c beam.cpp $(FLAG)
clean:
	rm -f *.o main
.PHONY: clean
