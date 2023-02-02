bdir=build
sdir=src

header_files  = ${sdir}/Enums.h \
				${sdir}/Views/View.h \
				${sdir}/Views/OptionScreenView.h \
				${sdir}/Views/StartScreenView.h \
				${sdir}/Views/PauseScreenView.h \
				${sdir}/Views/CustomScreenView.h \
				${sdir}/Views/GameoverScreenView.h \
				${sdir}/Views/SmallScreenView.h

source_files  = ${sdir}/main.cpp \
				${sdir}/Views/View.cpp \
				${sdir}/Views/OptionScreenView.cpp \
				${sdir}/Views/StartScreenView.cpp \
				${sdir}/Views/PauseScreenView.cpp \
				${sdir}/Views/CustomScreenView.cpp \
				${sdir}/Views/GameoverScreenView.cpp \
				${sdir}/Views/SmallScreenView.cpp

tetris : $(source_files) $(header_files)
	g++ -O2 -g -std=c++17 $(source_files) -pthread -lncurses -I "src" -o ${bdir}/tetris

clean :
	rm -r $(bdir)

$(info $(shell mkdir -p $(bdir)))
