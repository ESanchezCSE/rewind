all:
	g++ main.o behave.o db.o -o rewind
	
main.o: main.cpp
	g++ -c main.cpp

behave.o: behave.cpp declare.h
	g++ -c behave.cpp

db.o: db.cpp db.h
	g++ -c db.cpp

clean:
	rm *.o 