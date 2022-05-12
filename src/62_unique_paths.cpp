#include <stdio.h>

#include <cstdlib>
#include <vector>
#include <ctime>

using std::vector;

int UniquePaths(const int &m, const int &n);

// void InitializeIvv(vector<vector<int>> &ivv, const int &m, const int &n) {
//   for (int i = 0; i < m; ++i) {
//     for (int j = 0; j < n; ++j) ivv.push_back(0);
//   }
// }

int SolutionOne(const int &m, const int &n) {
	vector<vector<int>> ivv(m, vector<int>(n));
	// InitializeIvv(ivv);
	ivv[0][0] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			ivv[0][j] = 1;
			ivv[i][0] = 1;
			if (i >= 1 && j >= 1) ivv[i][j] = ivv[i - 1][j] + ivv[i][j - 1];
		}
	}
	printf("%d\n", ivv[m -1][n - 1]);
	return ivv[m - 1][n - 1];
}

int Solution(const int &m, const int &n) {
	srand(time(NULL));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: return SolutionOne(m, n); break;
	}
}

void Test098() {
	int m, n;
	while ((scanf("%d %d", &m, &n)) != EOF) { Solution(m, n); }
	printf("end of Test098\n");
}

int main(int argc, char **argv) {
	Test098();
}
