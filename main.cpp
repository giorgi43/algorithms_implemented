#include <chrono> // for measuring function runtime
#include <algorithm>
#include "file_handler.h"
#include "sorting_algos.h"

using namespace std;

void printArray(std::vector<int> arr, unsigned tillPos) {
	for(unsigned i = 0; i < tillPos; i++) {
		cout << arr[i] << " " << endl;
	}
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		cerr << "./main filename.txt" << endl;
		return 1;
	}

	ifstream file;
	file.open(argv[1]);
	vector<int> nums;

	cout << "Loading numbers into vector..." << endl;
	loadIntoArray(file, nums);
	cout << "Numbers loaded successfully" << endl;

	//printArray(nums, 10);
	
	auto t1 = chrono::high_resolution_clock::now();
	//insertionSort(nums);
	//selectionSort(nums)
	//mergeSort(nums, 0, nums.size()-1);
	//sort(nums.begin(), nums.end()); // std::sort
	quickSort(nums, 0, nums.size());
	auto t2 = chrono::high_resolution_clock::now();
	
	auto duration = chrono::duration_cast<chrono::microseconds>( t2 - t1 ).count();
	
	cout << "Array sorted, took " << duration << " microseconds." << endl;
	
	//printArray(nums, 10);

	return 0;
}
