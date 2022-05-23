#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;

int MajorityElement(vector<int> &nums);

int SolutionOne(vector<int> &nums) {
	unordered_map<int, int> hashtable;
	int cur_cnt = 0;
	int size = nums.size();
	/* lower half */
	int half_size = size >> 1;

	for (const auto &i : nums) {
		++hashtable[i];
		cur_cnt = hashtable[i];
		if (cur_cnt > half_size) return i;
	}
	return -1;
}

int SolutionTwo(vector<int> &nums) {
	std::sort(nums.begin(), nums.end());
	return nums[(nums.size() - 1) >> 1];
}

int Solution(vector<int> &nums) {
	srand(time(nullptr));
	int rand_int = rand() % 2 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(nums);
		case 2: printf("SolutionTwo\n"); return SolutionTwo(nums);
	}
	return -1;
}

void Test00169() {
	int res = 0;
	// vector<int> nums = {3, 2, 3};
	vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
	res = Solution(nums);
	printf("%d\n", res);
	printf("end of Test00169\n");
}

int main(int argc, char **argv) {
	Test00169();
}

