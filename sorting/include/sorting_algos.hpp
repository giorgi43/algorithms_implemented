#ifndef SORTING_ALGOS_H
#define SORTING_ALGOS_H
#include <algorithm> // std::swap
#include <stdlib.h>
#include <time.h>

/*
* Helper function for merge sort
*/
template <typename T>
static void merge(std::vector<T>& v, std::size_t startIndex, std::size_t midIndex, std::size_t endIndex) {
	auto n1 = midIndex - startIndex + 1;
	auto n2 = endIndex - midIndex;

	std::vector<T> left(n1);
	std::vector<T> right(n2);

	// Extract first and second half into left and right vectors
	for (auto i = 0; i < n1; ++i) {
		left[i] = v[startIndex+i];
	}
	for (auto i = 0; i < n2; ++i) {
		right[i] = v[midIndex+i+1];
	}
	
	// Merge
	int i = 0;
	int j = 0;
	int k = startIndex;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			v[k] = left[i];
			i++;
		} else {
			v[k] = right[j];
			j++;
		}
		k++;
	}

	// Copy remaining elements if there are eny
	while (i < n1) {
		v[k] = left[i];
		i++;
		k++;
	}
	while (j < n2) {
		v[k] = right[j];
		j++;
		k++;
	}
}

/*
* Helper function for quick sort. no random choose
*/
template <typename T>
static std::size_t partition(std::vector<T>& v, std::size_t startIndex, std::size_t endIndex) {	
	T x = v[startIndex];
	auto i = startIndex;
	for (auto j = startIndex+1; j < endIndex; ++j) {
		if (v[j] <= x) {
			i++;
			std::swap(v[i], v[j]);
		}
	}

	std::swap(v[i], v[startIndex]);
	return i;
}

/*
* Helper function for quick sort. random choose. for now takes longer time and needs fix?
*/
/*static int randPartition(std::vector<int>& v, unsigned startIndex, unsigned endIndex) {
	srand(time(NULL));
	unsigned randIndex = startIndex + rand()%(endIndex-startIndex);
	std::swap(v[randIndex], v[startIndex]);

	return partition(v, startIndex, endIndex);
}*/

/*
* selection sort
* complexity O(n^2)
*/
template <typename T>
void selectionSort(std::vector<T>& v) {
	for (auto index = 0; index < v.size(); ++index) {
		auto smallestNumIndex = index;
		for (auto i = index+1; i < v.size(); ++i) {
			if (v[i] < v[smallestNumIndex]) {
				smallestNumIndex = i;
			}
		}
		//swapElements(unordered, index, smallestNumIndex);
		std::swap(v[index], v[smallestNumIndex]);
	}
}

/*
* insertion sort
* complexity O(n^2)
*/
template <typename T>
void insertionSort(std::vector<T>& v) {
	for (auto i = 1; i < v.size(); ++i) {
		for (auto j = i-1; j >= 0; --j) {
			if (v[j] < v[j+1]) break;
			//swapElements(unordered, j, j+1);
			std::swap(v[j], v[j+1]);
		}
	}
}

/*
* merge sort
* complexity O(n*log(n))
*/
template <typename T>
void mergeSort(std::vector<T>& v, std::size_t startIndex, std::size_t endIndex) {
	/* Using recursion */
	if (startIndex < endIndex) {
		auto mid = (startIndex+endIndex)/2;
		mergeSort(v, startIndex, mid);
		mergeSort(v, mid+1, endIndex);
		merge(v, startIndex, mid, endIndex);
	}
}

/*
* quick sort
* complexity O(n*log(n))
*/
template <typename T>
void quickSort(std::vector<T>& v, std::size_t startIndex, std::size_t endIndex) {
	std::size_t partitionPoint;
	if (startIndex < endIndex) {
		partitionPoint = partition(v, startIndex, endIndex);
		quickSort(v, startIndex, partitionPoint);
		quickSort(v, partitionPoint+1, endIndex);
	}
}

#endif
