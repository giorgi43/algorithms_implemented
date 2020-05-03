#include "sorting_algos.h"

/*
* Helper function to swap 2 elements in vectorArr
* Usage: swap(vectorArr, index1, index2);
*/
void swapElements(std::vector<int>& arr, unsigned firstIndex, unsigned secondIndex) {
	auto tmpFirst = arr[firstIndex];
	auto tmpSecond = arr[secondIndex];
	arr[firstIndex] = tmpSecond;
	arr[secondIndex] = tmpFirst;
}

/*
* Helper function for merge sort
*/
void merge(std::vector<int>& arr, unsigned startIndex, unsigned midIndex,  unsigned endIndex) {
	auto n1 = midIndex - startIndex + 1;
	auto n2 = endIndex - midIndex;

	std::vector<int> left(n1);
	std::vector<int> right(n2);

	// Extract first and second half into left and right vectors
	for(unsigned i = 0; i < n1; i++) {
		left[i] = arr[startIndex+i];
	}
	for(unsigned i = 0; i < n2; i++) {
		right[i] = arr[midIndex+i+1];
	}
	
	// Merge
	int i = 0;
	int j = 0;
	int k = startIndex;
	while(i < n1 && j < n2) {
		if(left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	// Copy remaining elements if there are eny
	while(i < n1) {
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j < n2) {
		arr[k] = right[j];
		j++;
		k++;
	}
}

/*
* Helper function for quick sort. no random choose
*/
int partition(std::vector<int>& v, unsigned startIndex, unsigned endIndex) {	
	int x = v[startIndex];
	int i = startIndex;
	for(int j = startIndex+1; j < endIndex; j++) {
		if(v[j] <= x) {
			i++;
			std::swap(v[i], v[j]);
		}
	}

	std::swap(v[i], v[startIndex]);
	return i;
}

/*
* Helper function for quick sort. random choose
*/
int randPartition(std::vector<int>& v, unsigned startIndex, unsigned endIndex) {
	srand(time(NULL));
	unsigned randIndex = startIndex + rand()%(endIndex-startIndex);
	std::swap(v[randIndex], v[startIndex]);

	return partition(v, startIndex, endIndex);
}


/*
* selection sort
* complexity O(n^2)
*/
void selectionSort(std::vector<int>& unordered) {
	for(unsigned index = 0; index < unordered.size(); index++) {
		unsigned smallestNumIndex = index;
		for(unsigned i = index+1; i < unordered.size(); i++) {
			if(unordered[i] < unordered[smallestNumIndex]) {
				smallestNumIndex = i;
			}
		}
		swapElements(unordered, index, smallestNumIndex);
		//std::swap(unordered[index], unordered[smallestNumIndex]);
	}
}

/*
* insertion sort
* complexity O(n^2)
*/
void insertionSort(std::vector<int>& unordered) {
	for(unsigned i = 1; i < unordered.size(); i++) {
		for(int j = i-1; j >= 0; j--) {
			if(unordered[j] < unordered[j+1]) break;
			swapElements(unordered, j, j+1);
		}
	}
}

/*
* merge sort
* complexity O(n*log(n))
*/
void mergeSort(std::vector<int>& unordered, unsigned startIndex, unsigned endIndex) {
	/* Using recursion */
	if(startIndex < endIndex) {
		auto mid = (startIndex+endIndex)/2;
		mergeSort(unordered, startIndex, mid);
		mergeSort(unordered, mid+1, endIndex);
		merge(unordered, startIndex, mid, endIndex);
	}
}

/*
* quick sort
* complexity O(n*log(n))
*/
void quickSort(std::vector<int>& unordered, unsigned startIndex, unsigned endIndex) {
	int partitionPoint;
	if(startIndex < endIndex) {
		partitionPoint = partition(unordered, startIndex, endIndex);
		quickSort(unordered, startIndex, partitionPoint);
		quickSort(unordered, partitionPoint+1, endIndex);
	}
}

