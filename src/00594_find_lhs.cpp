#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

int FindLHS(vector<int> &nums);

/* sliding window */
int SolutionOne(vector<int> &nums) {
	std::sort(nums.begin(), nums.end());
	int size = nums.size();
	if (size < 2) return 0;

	int lhs = 0, rhs = 1, len = 0;
	int max_len = 0;
	while (rhs < size) {
		if (nums[rhs] - nums[lhs] > 1) {
			if (lhs < rhs - 1) ++lhs;
			else { ++lhs; ++rhs; }
		}
		else if (nums[rhs] - nums[lhs] == 0) { ++rhs;  }
		// else if (nums[rhs] - nums[lhs] == 1) {
		else {
			len = rhs - lhs + 1;
			max_len = std::max(len, max_len);
			++rhs;
		}
	}
	return max_len;
}

int SolutionTwo(vector<int> &nums) {
	unordered_map<int, int> cnt;
	for (const auto &i : nums) ++cnt[i];

	// int res = 0;
	// for (auto &[key, val] : cnt) {
	//   if (cnt.count(key + 1)) {
	//     res = std::max(res, val + cnt.at(key + 1));
	//   }
	// }
	int res = 0;
	for (auto it : cnt) {
		if (cnt.count(it.first + 1)) {
			res = std::max(res, cnt.at(it.first + 1) + it.second);
		}
	}
	return res;
}

int Solution(vector<int> &nums) {
	srand(time(nullptr));
	int rand_int = rand() % 2 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(nums); break;
		case 2: printf("SolutionTwo\n"); return SolutionTwo(nums); break;
	}
	return -1;
}

void Test00594(void) {
	vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
	nums = {1, 1, 1, 1};
	nums = {1, 2, 3, 4};
	int res = Solution(nums);
	for (const auto &i : nums) printf("%d ", i);
	printf("\n");
	printf("res = %d\n", res);
}

int main(int argc, char **argv) {
	Test00594();
}
