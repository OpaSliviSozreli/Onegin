CXX = g++
SOURCES = main.cpp print.cpp bubble_sort.cpp sort_backwards.cpp
EXECUTABLE_FILE = sort_onegin
CFLAGS = -b
WARNINGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: sort_onegin

sort_onegin: main.o print.o bubble_sort.o sort_backwards.o
	$(CXX) $(SOURCES) -o $(EXECUTABLE_FILE) $(WARNINGS)

main.o: main.cpp
	$(CXX) main.cpp -c

print.o: print.cpp
	$(CXX) print.cpp -c

bubble_sort.o: bubble_sort.cpp
	$(CXX) bubble_sort.cpp -c

sort_backwards.o: sort_backwards.cpp
	$(CXX) sort_backwards.cpp -c