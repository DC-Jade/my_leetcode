#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

#include "../include/ivv.hpp"
using std::vector;

int FindTheDistanceValue(const vector<int> &arr1, const vector<int> &arr2, int d);

bool IsDistance(const int &val, const vector<int> &iv, const int &d) {
	for (const auto &i : iv) {
		if (std::abs(val - i) <= d) return false;
	}
	return true;
}

int SolutionOne(const vector<int> &arr1, const vector<int> &arr2, int d) {
	int res = 0;
	for (const auto &i : arr1) { if (IsDistance(i, arr2, d)) ++res; }
	return res;
}


int Solution(const vector<int> &arr1, const vector<int> &arr2, int d) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne: \n"); return SolutionOne(arr1, arr2, d);
		// case 2:	printf("SolutionTwo: \n"); return SolutionTwo(nums);
	}
	return {0};
}

void Test01385() {
	int res = 0;
	int d = 2;
	vector<int> arr1 = {4, 5, 8};
	vector<int> arr2 = {10, 9, 1, 8};
	res = Solution(arr1, arr2, d);
	printf("%d\n", res);
}

int main(int argc, char **argv) {
	Test01385();
}
