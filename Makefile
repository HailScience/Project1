#Makefile

CXX = g++


littleAnt: main.o Ant.o
	${CXX} main.o Ant.o -o littleAnt

main.o: main.cpp
	${CXX} -c main.cpp

Ant.o: Ant.cpp Ant.hpp
	${CXX} -c Ant.cpp

clean:
	rm *.o littleAnt
