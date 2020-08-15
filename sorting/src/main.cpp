#include <iostream>
#include <chrono> // for measuring function runtime
#include "../include/file_handler.hpp"
#include "../include/sorting_algos.hpp"

using namespace std;

void printArray(std::vector<int> arr, std::size_t tillPos) {
	for (auto i = 0; i < tillPos; ++i) {
		cout << arr[i] << '\n';
	}
}

int main(int argc, char *argv[]) {
	/*if(argc != 2) {
		cerr << "./main filename.txt" << endl;
		return 1;
	}*/

	ifstream file;
	file.open(argv[1]);
	vector<int> nums; //{22, 12, 122, 2, 1, 200, 0, -32, 10};

	//cout << "Loading numbers into vector...\n";
	//loadIntoVector(file, nums);
	//cout << "Numbers loaded successfully\n";

	printArray(nums, 10);
	
	auto t1 = chrono::high_resolution_clock::now();
	//insertionSort(nums);
	//selectionSort(nums);
	mergeSort(nums, 0, nums.size()-1);
	//sort(nums.begin(), nums.end()); // std::sort
	//quickSort(nums, 0, nums.size());
	auto t2 = chrono::high_resolution_clock::now();
	
	auto duration = chrono::duration_cast<chrono::microseconds>( t2 - t1 ).count();
	
	cout << "Array sorted, took " << duration << " microseconds." << endl;
	
	printArray(nums, 10);

	return 0;
}
