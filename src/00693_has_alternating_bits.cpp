#include <cstdlib>
#include <cstdio>
#include <ctime>

bool HasAlternatingBits(int n);
bool SolutionOne(int n);
bool Solution(int n);

bool SolutionOne(int n) {
	int tmp = n ^ (n >> 1);
	// return (((n ^ (n >> 1)) + 1) == 0);
	return (tmp & (tmp + 1)) == 0;
}

// bool SolutionTwo(int n) {
// }

bool Solution(int n) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(n); break;
	}
	return false;
}

void Test00693() {
	int n = 5;
	// n = 7;
	int res = Solution(n);
	printf("%d\n", res);
	printf("end of Test00693\n");
}

int main(int argc, char **argv) {
	Test00693();
}
