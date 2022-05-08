#ifndef INCLUDE_READ_ORDINARY_STRING_FILE_H
#define INCLUDE_READ_ORDINARY_STRING_FILE_H

#include <string>
#include <vector>
#include <fstream>
#include <assert.h>

using std::vector;
using std::string;

void ReadOrdinaryStringFile(vector<string> *pvec_str) {
	std::ifstream file("../data/58_ordinary_string.txt");
	string str;
	while (std::getline(file, str, '\n')) {
		assert(pvec_str != nullptr);	
		pvec_str->push_back(str);
	}
}

#endif
