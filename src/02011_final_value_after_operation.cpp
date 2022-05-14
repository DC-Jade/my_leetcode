#include <stdio.h>

#include <string>
#include <vector>
#include <fstream>

#include "../include/read_string_file.hpp"

using std::vector;
using std::string;

int SolutionOne(const vector<string> &operations) {
	int n = 0;
	for (auto op : operations) {
		if (op == "--X" || op == "X--") --n;
		else ++n;
	}
	return n;
}

/* only compare one char, three times faster than SolutionOne */
int SolutionTwo(const vector<string> &operations) {
	int n = 0;
	for (auto op : operations) {
		if (op[1] == '-') --n;
		else ++n;
	}
	return n;
}

int FinalValueAfterOperation(vector<string> &operations) {
	// return SolutionOne(operations);
	return SolutionTwo(operations);
}

void Test2011() {
	vector<string> operations;
	ReadStringFile(&operations);
	int ans = SolutionTwo(operations);
	printf("%d\n", ans);
	PrintVecStr(operations);
}

int main() {
	Test2011();
}


