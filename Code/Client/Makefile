client: main.o log_in.o instruction.o
	g++ main.o log_in.o instruction.o -o client

main.o: main.cpp
	g++ -c main.cpp

log_in.o: log_in.cpp
	g++ -c log_in.cpp

instruction.o:
	g++ -c instruction.cpp

clean:
	rm *.o client
