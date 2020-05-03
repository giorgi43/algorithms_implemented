#include <vector>
#include <algorithm> // std::swap
#include <stdlib.h>
#include <time.h>

/*
* Helper function to swap 2 elements in vectorArr
* Usage: swap(vectorArr, index1, index2);
*/
void swapElements(std::vector<int>& arr, unsigned firstIndex, unsigned secondIndex);

/*
* Helper function for merge sort
*/
void merge(std::vector<int>& arr, unsigned startIndex, unsigned midIndex, unsigned endIndex);

/*
* Helper function for quick sort, no random choose
*/
int partition(std::vector<int>& v, unsigned startIndex, unsigned endIndex);

/*
* Helper function for quick sort, random choose. for now takes longer time and needs fix?
*/
int randPartition(std::vector<int>& v, unsigned startIndex, unsigned endIndex);

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
