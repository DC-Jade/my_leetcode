#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>

int BinaryGap(int n);
int SolutionOne(int n);
int Solution(int n);

int SolutionOne(int n) {
	int residual = n;
	int low = -1;
	int res = 0;
	for (int i = 0; residual; ++i) {
		if (residual & 1) {
			if (low != -1) { res = std::max(res, i - low); }
			low = i;
		}
		// ++high;
		residual >>= 1;
	}
	return res;
}

int Solution(int n) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(n); break;
	}
	return -1;
}

void Test00868() {
	int n = 22;
	int res = Solution(n);
	printf("%d\n", res);
}

int main() {
	Test00868();
}

