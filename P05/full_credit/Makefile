CXXFLAGS = --std=c++17

all: gate

gate: main.o gate.o *.h

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
gate.o: gate.cpp *.h
	$(CXX) $(CXXFLAGS) -c gate.cpp -o gate.o

gate.gch: gate.h
	$(CXX) $(CXXFLAGS) -c gate.h -o gate.gch

clean:
	rm -f *.o *.gch ~* .o gate

