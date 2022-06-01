#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>

int BitwiseComplement(int n);
int SolutionOne(int n);
int Solution(int n);

int GetHighbit(int n) {
	int high_bit = 0;
	for (int i = 0; n > 0; ++i) {
		n >>= 1;
		high_bit = i;
	}
	return high_bit;
}

int SolutionOne(int n) {
	int high_bit = GetHighbit(n);
	int mask = 0;
	if (high_bit == 30) {
		/* avoid int overflow 0111 1111 1111 1111 1111 1111 1111 1111  */
		mask = 0x7fffffff;
	} else {
		mask = (1 << (high_bit + 1)) - 1;
	}
	int res = n ^ mask;
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

void Test01009() {
	int n = 5;
	n = 7;
	int res = Solution(n);
	printf("%d\n", res);
}

int main() {
	Test01009();
}

