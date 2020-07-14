g++ -c main.cpp Grid.cpp
g++ main.o Grid.o -o main -lsfml-graphics -lsfml-window -lsfml-system

rm -r *.o
