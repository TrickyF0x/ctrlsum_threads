all: main.cpp
	g++ main.cpp -o main -lstdc++fs -pthread
	g++ controlsum.cpp -o controlsum -pthread

clean:
	-rm *.out
	-rm *.o
	-rm *~