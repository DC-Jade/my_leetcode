#include <stdio.h>

#include <cstdlib>
#include <vector>

using std::vector;

int WaysToStep(const int &n);

int SolutionOne(const int &n) {
	vector<int> iv(n + 3, 0);
	/* base case */
	iv[0] = 1; iv[1] = 1; iv[2] = 2;
	for (int i = 3; i < n + 1; ++i) {
		iv[i] = iv[i - 1] + iv[i - 2] + iv[i - 3];
	}
	return iv[n];
}

int Solution(const int &n) {
	return SolutionOne(n);
}

void Test00801() {
	int res = 0;
	for (int n = 0; scanf("%d", &n) != EOF;) {
		res = Solution(n);
		printf("%d\n", res);
	}
	printf("end of Test00801\n");
}

int main() {
	Test00801();
}
