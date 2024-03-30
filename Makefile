# compiler options
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion

# list .h files here
<<<<<<< HEAD
HEADERS = Item.h Manager.h

# list .cpp files here
PROGRAM_FILES = main.cpp Item.cpp Manager.cpp
=======
HEADERS = *.h

# list .cpp files here
PROGRAM_FILES = *.cpp
>>>>>>> parent of 6b8d0c5 (Mar 30, 2024, 3:06 PM)

.PHONY: all
all: program.exe

program.exe: $(PROGRAM_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(PROGRAM_FILES) -o $@

.PHONY: clean
clean:
	rm -f program.exe
