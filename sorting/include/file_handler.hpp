#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

/*
* This code is responsible for loading random numbers from file to 
* Test sorting algorithms.
*/

#include <vector>
#include <fstream>

/*
* Loads numbers from file into vector
* File is regular txt file, one number per line
*/
void loadIntoVector(std::ifstream& file, std::vector<int>& v);

#endif
