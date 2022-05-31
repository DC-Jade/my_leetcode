#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>

#include <cstdint>

uint32_t ReverseBits(uint32_t n);
uint32_t SolutionOne(uint32_t n);
uint32_t Solution(uint32_t n);

uint32_t SolutionOne(uint32_t n) {
	uint32_t rev = 0;
	for (int i = 0; i < 32 && 31 > 0; ++i) {
		rev |= (n & 1) << (n - i);
		n >>= 1;
	}
	return rev;
}

uint32_t Solution(uint32_t n) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(n); break;
	}
	return 0;
}

void Test00190() {
	uint32_t n = 1;
	uint32_t res = Solution(n);
	printf("%d\n", res);
}

int main(int argc, char **argv) {
	Test00190();
}
