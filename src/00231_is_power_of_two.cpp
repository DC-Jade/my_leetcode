#include <cstdio>
#include <cstdlib>
#include <ctime>

bool IsPowerOfTwo(int n);
bool SolutionOne(int n);
bool Solution(int n);

bool SolutionOne(int n) {
	int cnt = 0;
	while (n > 0) {
		if (n & 1) ++cnt;
		n /= 2;
	}
	return cnt == 1 ? true : false;
}

bool SolutionTwo(int n) {
	/* n & (n - 1) remove 1 in lower bit */
	// return n > 0 && ( n & (n - 1) == 0);
	/* n & (-n) get 1 in lower bit */
	return n > 0 && n == (n & (-n));
}

bool Solution(int n) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 2;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(n); break;
		case 2: printf("SolutionTwo\n"); return SolutionTwo(n); break;
	}
	return false;
}

void Test00231() {
	int n = 1;
	n = 16;
	// n = 3;
	bool res = Solution(n);
	res ? printf("True\n") : printf("False\n");
}

int main(int argc, char **argv) {
	Test00231();
}
