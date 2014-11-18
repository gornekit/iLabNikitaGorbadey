all: calculator

main.o: calMain.cpp 
	g++ -c -o main.o calMain.cpp

stack.o: MyStackFunctions.cpp MyStack.h
	g++ -c -o stack.o MyStackFunctions.cpp

cal.o: calFunctions.cpp Calculate.h
	g++ -c -o cal.o calFunctions.cpp

calculator: main.o stack.o cal.o
	g++ -o calculator main.o stack.o cal.o

clean: 
	rm -rf main.o
	rm -rf cal.o
	rm -rf stack.o
