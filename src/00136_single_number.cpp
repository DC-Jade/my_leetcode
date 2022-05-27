#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>

#include <vector>

using std::vector;

int FindTheDifference(vector<int> &nums);

/* bit operation, xor */
int SolutionOne(vector<int> &nums) {
	int res = 0;
	for (const auto &num : nums) { res ^= num; }
	return res;
}

int Solution(vector<int> &nums) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(nums); break;
	}
	return ' ';
}

void Test00136() {
	vector<int> nums = {4,1,2,1,2};
	int res = Solution(nums);
	printf("%d\n", res);
}

int main() {
	Test00136();
}
