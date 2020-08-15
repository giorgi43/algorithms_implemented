#include "../include/file_handler.hpp"

void loadIntoVector(std::ifstream& file, std::vector<int>& v) {
	int num;
	while(file >> num) {
		v.push_back(num);
	}
}
