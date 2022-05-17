#include <stdio.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using std::vector;

int MinPairSum(vector<int> &nums);

int SolutionOne(vector<int> &nums) {
	int size = nums.size();
	int max_pair = 0;
	int mid_size = size >> 1;

	sort(nums.begin(), nums.end());
	for (int i = 0; i < mid_size; ++i) {
		max_pair = std::max(max_pair, nums[i] + nums[size - i - 1]);
	}

	printf("%d\n", max_pair);
	return max_pair;
}

int Solution(vector<int> &nums) {
	return SolutionOne(nums);
}

void Test01877() {
	vector<int> nums = {3, 5, 2, 3};
	nums = {3, 5, 4, 2, 4, 6};
	Solution(nums);
}

int main() {
	Test01877();
}


