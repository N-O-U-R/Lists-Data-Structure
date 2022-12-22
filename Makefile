all:compile link run
compile:
	g++ -c -I "./include" ./src/Source.cpp -o ./lib/Source.o

link:
	g++ ./lib/Source.o -o ./bin/Program
run:
	./bin/program