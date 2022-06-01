#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>

using std::vector;

int MissingNumber(vector<int> &nums);
int SolutionOne(vector<int> &nums);
int Solution(vector<int> &nums);

int SolutionOne(vector<int> &nums) {
	int res = 0;
	for (const auto &i : nums) res ^= i;
	int size = nums.size();
	for (int i = 0; i < size; ++i) res ^= i + 1;
	return res;
}

int Solution(vector<int> &nums) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(nums); break;
	}
	return -1;
}

void Test00268() {
	vector<int> nums = {3, 0, 1};
	int res = Solution(nums);
	printf("res = %d\n", res);
	printf("end of Test00268\n");
}

int main(int argc, char **argv) {
	Test00268();
}
