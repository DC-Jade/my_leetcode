#include <cstdio>
#include <cstdlib>
#include <ctime>

bool IsPowerOfFour(int n);
bool SolutionOne(int n);
bool Solution(int n);

bool SolutionOne(int n) {
	int cnt = 0;
	while (n > 0) {
		if (n & 1) ++cnt;
		n = n << 2;
	}
	return cnt == 1 ? true : false;
}

bool SolutionTwo(int n) {
	// return n > 0 && ( n & (n - 1) == 0);
	/* n & (-n) get 1 in lower bit */
	/* n is power of 2 and n % 3 == 1 */
	/* n = 4 ^ x = (3 + 1)  ^ x  */
	/* n % 3 = 1 */
	return n > 0 && n == (n & (-n)) && (n % 3 == 1);
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

void Test00342() {
	int n = 1;
	n = 16;
	n = 2;
	n = 1;
	// n = 3;
	bool res = Solution(n);
	res ? printf("True\n") : printf("False\n");
}

int main(int argc, char **argv) {
	Test00342();
}
