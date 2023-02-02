bdir=build
sdir=src

tetris : ${sdir}/main.cpp ${sdir}/Enums.h ${sdir}/Views/View.cpp ${sdir}/Views/View.h ${sdir}/Views/StartScreenView.cpp ${sdir}/Views/StartScreenView.h 
	g++ -O2 -g -std=c++17 ${sdir}/main.cpp ${sdir}/Views/View.cpp ${sdir}/Views/StartScreenView.cpp -pthread -lncurses -o ${bdir}/tetris

clean :
	rm -r $(bdir)

$(info $(shell mkdir -p $(bdir)))

# TODO: includepath to src
# TODO: put all header and source file in variables