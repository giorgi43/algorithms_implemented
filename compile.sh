g++ -c file_handler.cpp sorting_algos.cpp main.cpp -O2
g++ -o main file_handler.o sorting_algos.o main.o -O2

rm -r *.o
