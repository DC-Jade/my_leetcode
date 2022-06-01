#include <cstdlib>
#include <cstdio>
#include <ctime>

int HanminDistance(int x, int y);
int SolutionOne(int x, int y);
int SolutionTwo(int x, int y);
int Solution(int x, int y);

int SolutionOne(int x, int y) {
	int cnt = 0;
	int left = x ^ y;
	/* count 1 cnt */
	while (left != 0) {
		if (left & 1) ++cnt;
		left = left >> 1;
	}
	return cnt;
}

int SolutionTwo(int x, int y) {
	int left = x ^ y;
	int cnt = 0;
	while (left) {
		/* left ^ (left - 1) can remove lower 1 */
		left &= left - 1;
		++cnt;
	}
	return cnt;
}

int Solution(int x, int y) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 2;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(x, y); break;
		case 2: printf("SolutionTwo\n"); return SolutionTwo(x, y); break;
	}
	return -1;
}

void Test00461() {
	int x = 1, y = 4;
	int res = Solution(x, y);
	printf("%d\n", res);
	printf("end of Test00461\n");
}

int main(int argc, char **argv) {
	Test00461();
}
