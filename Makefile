ifeq ($(OS), Windows_NT)
	CXX = g++
	INCLUDES = -I./include
	LIBS = -L./lib/windows -lraylib -lgdi32 -lwinmm
	EXE = main.exe
else
	CXX = g++
	INCLUDES = -I./include 
	LIBS = -L./lib/linux -lraylib
	EXE = main.out
endif

all:
	$(CXX) $(INCLUDES) ./src/*.cpp $(LIBS) -o $(EXE)