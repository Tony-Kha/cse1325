CXXFLAGS = --std=c++17

all: match

match: main.o tile.o board.o *.h
	$(CXX) $(CXXFLAGS) main.o tile.o board.o -o match

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
tile.o: tile.cpp *.h
	$(CXX) $(CXXFLAGS) -c tile.cpp -o tile.o
board.o: board.cpp *.h
	$(CXX) $(CXXFLAGS) -c board.cpp -o board.o

tile.gch: tile.h
	$(CXX) $(CXXFLAGS) -c tile.h -o tile.gch
board.gch: board.h
	$(CXX) $(CXXFLAGS) -c board.h -o board.gch

clean:
	rm -f *.o *.gch ~* .o match
