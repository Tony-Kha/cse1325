CXXFLAGS = --std=c++17

all: modulo1 modulo2

modulo1: main.o modulo.o *.h
	$(CXX) $(CXXFLAGS) main.o modulo.o -o modulo1
modulo2: main2.o modulo.o *.h
	$(CXX) $(CXXFLAGS) main2.o modulo.o -o modulo2

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
main2.o: main2.cpp *.h
	$(CXX) $(CXXFLAGS) -c main2.cpp -o main2.o
modulo.o: modulo.cpp *.h
	$(CXX) $(CXXFLAGS) -c modulo.cpp -o modulo.o

modulo.gch: modulo.h
	$(CXX) $(CXXFLAGS) -c modulo.h -o modulo.gch

clean:
	rm -f *.o *.gch ~* .o modulo1 modulo2
