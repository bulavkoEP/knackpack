all: dfs.o conditions.o knapsack.o 
	g++ -o dfs dfs.o conditions.o knapsack.o 
dfs.o: dfs.cpp conditions.h knapsack.h 
	g++ -c dfs.cpp

conditions.o: conditions.cpp conditions.h
	g++ -c conditions.cpp

knapsack.o: knapsack.cpp knapsack.h
	g++ -c knapsack.cpp

clean: cleanobj cleanmain

cleanobj:
	rm -f *.o

cleanmain:
	rm knapsack

.PHONY: clean cleanobj cleanmain