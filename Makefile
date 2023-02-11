bdir=build
sdir=src

header_files  = ${sdir}/Application.h \
				${sdir}/EventQueue.h \
				${sdir}/Controller.h \
				${sdir}/Enums.h \
				${sdir}/Views/View.h \
				${sdir}/Views/Colors.h \
				${sdir}/Views/OptionScreenView.h \
				${sdir}/Views/StartScreenView.h \
				${sdir}/Views/PauseScreenView.h \
				${sdir}/Views/CustomScreenView.h \
				${sdir}/Views/GameoverScreenView.h \
				${sdir}/Views/SmallScreenView.h \
				${sdir}/Views/GameScreenView.h \
				${sdir}/Models/Model.h \

source_files  = ${sdir}/main.cpp \
				${sdir}/Application.cpp \
				${sdir}/EventQueue.cpp \
				${sdir}/Controller.cpp \
				${sdir}/Views/View.cpp \
				${sdir}/Views/OptionScreenView.cpp \
				${sdir}/Views/StartScreenView.cpp \
				${sdir}/Views/PauseScreenView.cpp \
				${sdir}/Views/CustomScreenView.cpp \
				${sdir}/Views/GameoverScreenView.cpp \
				${sdir}/Views/SmallScreenView.cpp \
				${sdir}/Views/HelpScreenView.cpp \
				${sdir}/Views/GameScreenView.cpp \
				${sdir}/Models/Model.cpp \

tetris : $(source_files) $(header_files)
	g++ -O2 -g -std=c++17 $(source_files) -pthread -lncurses -I "src" -o ${bdir}/tetris

clean :
	rm -r $(bdir)

$(info $(shell mkdir -p $(bdir)))
