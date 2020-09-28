CXXFLAGS = --std=c++17

all: gate

gate: main.o gate.o and.o or.o *.h

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
gate.o: gate.cpp *.h
	$(CXX) $(CXXFLAGS) -c gate.cpp -o gate.o
and.o: and.cpp *.h
	$(CXX) $(CXXFLAGS) -c and.cpp -o and.o
or.o: or.cpp *.h
	$(CXX) $(CXXFLAGS) -c or.cpp -o or.o

gate.gch: gate.h
	$(CXX) $(CXXFLAGS) -c gate.h -o gate.gch
and.gch: and.h
	$(CXX) $(CXXFLAGS) -c and.h -o and.gch
or.gch: or.h
	$(CXX) $(CXXFLAGS) -c or.h -o or.gch

clean:
	rm -f *.o *.gch ~* .o gate

