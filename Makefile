CXX = g++
SOURCES = main.cpp print.cpp bubble_sort.cpp
EXECUTABLE_FILE = sort_onegin
WARNINGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: sort_onegin

sort_onegin: main.o print.o bubble_sort.o
	$(CXX) $(SOURCES) -o $(EXECUTABLE_FILE) $(WARNINGS)

main.o: main.cpp
	$(CXX) main.cpp

print.o: print.cpp
	$(CXX) print.cpp

bubble_sort.o: bubble_sort.cpp
	$(CXX) bubble_sort.cpp
