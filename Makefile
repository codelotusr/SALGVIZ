all:
	g++ --std=c++20 -I src/include -L src/lib -o turtle main.cpp -lmingw32 -lSDL2main -lSDL2