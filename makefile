all: list

flags = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

list: a.exe
	a.exe Dump.dot

a.exe: main.o PushPop.o InitDtor.o Dump.o
	g++ main.o PushPop.o InitDtor.o Dump.o

main.o: main.cpp
	g++ -c $(flags) main.cpp

PushPop.o: PushPop.cpp
	g++ -c $(flags) PushPop.cpp

InitDtor.o: InitDtor.cpp
	g++ -c $(flags) InitDtor.cpp

Dump.o: Dump.cpp
	g++ -c $(flags) Dump.cpp

clean:
	rm -rf *.o *.exe
