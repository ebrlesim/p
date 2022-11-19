all: 
	g++ -c halo.cpp
	g++ halo.o -o halo -lsfml-graphics -lsfml-window -lsfml-system
	halo.exe