bdir=build
sdir=src

tetris : ${sdir}/main.cpp
	g++ -O2 -g -std=c++17 ${sdir}/main.cpp -pthread -lncurses -o ${bdir}/tetris

clean :
	rm -r $(bdir)

$(info $(shell mkdir -p $(bdir)))