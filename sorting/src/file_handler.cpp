#include "../include/file_handler.h"

void loadIntoArray(std::ifstream& file, std::vector<int>& arr) {
	int num;
	while(file >> num) {
		arr.push_back(num);
	}
}
