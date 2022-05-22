#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

#include "../include/ivv.hpp"
using std::vector;

vector<vector<int>> FlipAndInvertImage(vector<vector<int>> &image);

void Reverse(vector<int> &iv) {
	int lhs = 0;
	int rhs = iv.size() - 1;
	while (lhs < rhs) { std::swap(iv[lhs++], iv[rhs--]); }
}

void Flip(vector<int> &iv) {
	for (auto &i : iv) { i = !i; };
}

vector<vector<int>> SolutionOne(vector<vector<int>> &image) {
	for (auto &iv : image) { Reverse(iv); Flip(iv); }
	return image;
}

vector<vector<int>> Solution(vector<vector<int>> &image) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne: \n"); return SolutionOne(image);
	}
	return {{0}, {0}};
}

void Test00832() {
	vector<vector<int>> image = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
	Solution(image);
	intvectorvector::PrintIVV(image);
}

int main(int argc, char **argv) {
	Test00832();
}
