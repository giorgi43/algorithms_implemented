#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <vector>
#include <fstream>

/*
* Loads numbers from file into vector array
* File is regular txt file, one number per line
*/
void loadIntoArray(std::ifstream& file, std::vector<int>& arr);

#endif
