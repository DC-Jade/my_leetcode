#include <cstdlib>
#include <cstdio>
#include <ctime>

int MinBitFlips(int start, int goal);
int SolutionOne(int start, int goal);
int Solution(int start, int goal);

int SolutionOne(int start, int goal) {
	int cnt = 0;
	int residual = start ^ goal;

	/* count one number */
	while (residual) {
		residual = residual & (residual - 1);
		++cnt;
	}
	return cnt;
}

int Solution(int start, int goal) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(start, goal); break;
	}
	return -1;
}

void Test02220() {
	int start = 10, goal = 7;
	int res = Solution(start, goal);
	printf("res = %d\n", res);
	printf("end of Test02220\n");
}

int main(int argc, char **argv) {
	Test02220();
}
