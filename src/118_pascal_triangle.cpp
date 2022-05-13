#include <stdio.h>
#include <assert.h>

#include <vector>

#include "../include/print_ivv.hpp"

using std::vector;

vector<vector<int>> SolutionOne(const int &n) {
	/* should initialize with push_back, or have element is zero */
	vector<vector<int>> ivv;
	/* initialization */
	for (int i = 0; i < n; ++i) {	
		vector<int> iv;	/* iv should be construt in loop, iv is a new vector */
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || i == j) iv.push_back(1);
			else iv.push_back(0);
		}
		ivv.push_back(iv);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j != 0 && i != j) {
				/* check index is legal */
				assert(&(ivv[i - 1][j]) != nullptr);
				ivv[i][j] = ivv[i - 1][j - 1] + ivv[i - 1][j];
			}
		}
	}
	PrintIVV(ivv);
	return ivv;
}

void Test118() {
	int n;
	while ((scanf("%d", &n)) != EOF) SolutionOne(n);
	printf("end of Test118\n");
}

int main(int argc, char **argv) {
	Test118();
}
