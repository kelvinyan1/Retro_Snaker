game.exe: game.o snack.o map.o
		g++ game.o snack.o map.o
game.o: game.cpp map.h snack.h
		g++ -c game.cpp map.h snack.h
snack.o: snack.cpp snack.h
		g++ -c snack.cpp snack.h
map.o: map.cpp map.h
		g++ -c map.cpp map.h
