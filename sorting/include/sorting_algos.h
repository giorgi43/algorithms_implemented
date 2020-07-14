#ifndef SORTING_ALGOS
#define SORTING_ALGOS

#include <vector>

/*
* selection sort
* complexity O(n^2)
*/
void selectionSort(std::vector<int>& unordered);

/*
* insertion sort
* complexity O(n^2)
*/
void insertionSort(std::vector<int>& unordered);

/*
* merge sort
* complexity O(n*log(n))
*/
void mergeSort(std::vector<int>& unordered, unsigned startIndex, unsigned endIndex);

/*
* quick sort
* complexity (n*log(n)). choose pivot randomly
*/
void quickSort(std::vector<int>& unordered, unsigned startIndex, unsigned endIndex);

#endif
