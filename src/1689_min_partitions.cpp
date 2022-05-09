#include <stdio.h>
#include <assert.h>

#include <string>
#include <fstream>

#include "../include/read_ordinary_string_file.hpp"

using std::string;

int SolutionOne(const string &str) {
	int maximum = 0;
	int c_int = 0;
	for (auto c : str) {
		c_int = c - '0';
		assert(c_int >= 0 && c_int <= 9);
		if (maximum < c_int) std::swap(maximum, c_int);
	}
	return maximum;
}

int SolutionTwo(const string &str) {
	int maximum = 0;
	int c_int = 0;
	for (auto c : str) {
		c_int = c - '0';
		assert(c_int >= 0 && c_int <= 9);
		// if (maximum < c_int) std::swap(maximum, c_int);
		/* get maximum number */
		maximum = std::max(maximum, c_int);
	}
	return maximum;
}

int Solution(const string &str) {
	int rand_int = rand() % 1;
	switch (rand_int) {
		case 0: return SolutionOne(str); break;
		case 1: return SolutionTwo(str); break;
	}
	printf("no hit case\n");
	return 0;
}

void Test1689() {
	string str = "";
	int min_cnt = 0;
	string data_path = "../data/1689_number_string.txt";
	vector<string> vec_str;
	ReadOrdinaryStringFile(&vec_str, data_path.c_str());
	for (auto str : vec_str) {
		min_cnt = Solution(str);
		printf("%d\n", min_cnt);
		min_cnt = 0;
	}
}

int main(int argc, char *argv[]) {
	Test1689();
}

