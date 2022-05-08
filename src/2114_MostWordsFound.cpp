#include <stdio.h>
#include <vector>
#include <string>

#include <algorithm>

#include "../include/read_ordinary_string_file.hpp"

int CountMaxSpaceOne(const vector<string> *pvec_str) {
	int max = 0;
	int count_space = 0;
	for (auto str : (*pvec_str)) {
		count_space = 0;
		for (auto chr : str) if (chr == ' ') ++count_space; 
		if (max < count_space) std::swap(max, count_space);
	}
	return max;
} 

int CountMaxSpaceTwo(const vector<string> *pvec_str) {
	int max = 0;
	int count_space = 0;
	for (auto str : (*pvec_str)) {
		count_space = 0;
		// for (auto chr : str) if (chr == ' ') ++count_space;
		/* use std::count, count element currence in array */
		count_space = count(str.begin(), str.end(), ' ');
		if (max < count_space) std::swap(max, count_space);
	}
	return max;
} 

int CountMaxSpace(const vector<string> *pvec_str) {
	int n = std::rand() % 2;
	switch (n) {
		case 1:
			return CountMaxSpaceOne(pvec_str); break;
		case 2:
			return CountMaxSpaceTwo(pvec_str); break;
	}
}

int Test2114() {
	int count_max_space = 0;
	int count_max = 1;
	vector<string> vec_str;
	ReadOrdinaryStringFile(&vec_str);
	count_max_space = CountMaxSpace(&vec_str);
	count_max = count_max_space + 1;
	printf("%d\n", count_max);
	return CountMaxSpace(&vec_str);
}

int main() {
	Test2114();
}
