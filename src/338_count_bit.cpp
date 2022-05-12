#include <stdio.h>


#include <cstdlib>
#include <vector>
#include <ctime>

using std::vector;

void PrintIntVector(const vector<int> &iv, const int &n) {
	for (auto i : iv) printf("%d ", i);
	printf("\n");
}

/* dp[0, n] */
vector<int> SolutionOne(const int &n) {
	/* dp[0] = 0 */
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < n + 1; ++i) {
		/* i & 1 == 1 odd, else even */
		if (i & 1) dp[i] = dp[i - 1] + 1;
		else dp[i] = dp[i >> 1];
	}
	return dp;
}

vector<int> Solution(const int &n) {
	srand(time(NULL));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: return SolutionOne(n); break;
	}
}

void Test338() {
	int n = 0;
	vector<int> iv;
	while (scanf("%d", &n) != EOF) {
		iv = Solution(n);
		PrintIntVector(iv, n);
	}
	printf("end of Test338\n");
}

int main() {
	Test338();
}

