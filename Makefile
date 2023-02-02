bdir=build
sdir=src

header_files  = ${sdir}/Enums.h \
				${sdir}/Views/View.h \
				${sdir}/Views/StartScreenView.h

source_files  = ${sdir}/main.cpp \
				${sdir}/Views/View.cpp \
				${sdir}/Views/StartScreenView.cpp

tetris : $(source_files) $(header_files)
	g++ -O2 -g -std=c++17 $(source_files) -pthread -lncurses -I "src" -o ${bdir}/tetris

clean :
	rm -r $(bdir)

$(info $(shell mkdir -p $(bdir)))
