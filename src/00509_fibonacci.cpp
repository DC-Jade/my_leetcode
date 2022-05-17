#include <stdio.h>
#include <assert.h>

#include <cstdlib>
#include <vector>
#include <ctime>

using std::vector;

int Solution(const int &n);
int SolutionOne(const int &n);
int Fibonacci(const int &n);

/* dp */
int SolutionOne(const int &n) {
	vector<int> iv(n + 1, 0);
	/* base case */
	iv[0] = 0;
	iv[1] = 1;
	for (int i = 2; i <= n; ++i) { iv[i] = iv[i - 1] + iv[i - 2]; }
	return iv[n];
}

/* recursion */
int SolutionTwo(const int &n) {
	if (n == 0 || n == 1) return n;
	else return SolutionTwo(n - 1) + SolutionTwo(n - 2);
}

/* recursion with memory, quick as dp */
int Helper(vector<int> &iv, const int &n) {
	if (n == 0 || n == 1) return n;
	if (iv[n] != 0) return iv[n];
	iv[n] = Helper(iv, n - 1) + Helper(iv, n - 2);
	return iv[n];
}

int SolutionThree(const int &n) {
	assert(n >= 0);
	if (n == 0 || n == 1) return n;
	vector<int> iv(n + 1, 0);
	return Helper(iv, n);
}

int Solution(const int &n) {
	srand(time(nullptr));
	int rand_int = rand() % 3 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne: ");		return SolutionOne(n);		break;
		case 2:	printf("SolutionTwo: ");		return SolutionTwo(n);		break;
		case 3: printf("SolutionThree: ");	return SolutionThree(n);	break;
	}
	return -1;
}

void Test00509() {
	int res = 0;
	for (int n = 0; scanf("%d", &n) != EOF;) {
		res = Solution(n);
		printf("%d\n", res);
	}
	printf("end of Test00509\n");
}

int main(int argc, char **argv) {
	Test00509();
}

