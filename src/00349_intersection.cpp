#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

#include "../include/ivv.hpp"
using std::vector;

vector<int> Intersection(const vector<int> &nums1, const vector<int> &nums2);

vector<int> SolutionOne(const vector<int> &nums1, const vector<int> &nums2) {
	int int_limit = 1001;
	vector<int> recurrence(int_limit, 0);
	vector<int> res_iv;

	vector<int> max_nums;
	vector<int> min_nums;
	int size_one = nums1.size(); int size_two = nums2.size();
	if (size_one > size_two) { max_nums = nums1; min_nums = nums2; }
	else  { max_nums = nums2; min_nums = nums1; }
	int min_size = min_nums.size();
	int max_size = max_nums.size();

	int cur_val = 0;
	for (int i = 0; i < max_size; ++i) {
		cur_val = max_nums[i];
		if (recurrence[cur_val] == 0) recurrence[cur_val] = 1;
	}

	std::sort(min_nums.begin(), min_nums.end());
	for (int j = 0; j < min_size; ++j) {
		while (j < min_size - 1 && min_nums[j] == min_nums[j + 1]) { ++j; }
		cur_val = min_nums[j];
		if (recurrence[cur_val]) res_iv.push_back(cur_val);
	}
	return res_iv;
}

// vector<int> SolutionTwo(const vector<int> &nums1, const vector<int> &nums2) {
// }

vector<int> Solution(const vector<int> &nums1, const vector<int> &nums2) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne: \n"); return SolutionOne(nums1, nums2);
		// case 2:	printf("SolutionTwo: \n"); return SolutionTwo(nums);
	}
	return {0};
}

void Test00349() {
	// vector<int> nums1 = {1, 2, 2, 1};
	// vector<int> nums2 = {2, 2};
	// vector<int> nums1 = {4, 9, 5};
	// vector<int> nums2 = {9, 4, 9, 8, 4};
	vector<int> nums1 = {8, 0, 3};
	vector<int> nums2 = {0, 0};
	vector<int> res_iv;
	res_iv = Solution(nums1, nums2);
	int size = res_iv.size();
	intvectorvector::PrintIV(res_iv, size);
}

int main(int argc, char **argv) {
	Test00349();
}
