all:
	g++ main.o behave.o -o rewind
	
main.o: main.cpp
	g++ -c main.cpp

behave.o: behave.cpp declare.h
	g++ -c behave.cpp

clean:
	rm *.o 