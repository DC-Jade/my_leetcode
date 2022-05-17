#include <stdio.h>

#include <vector>
#include <ctime>
#include <algorithm>

using std::vector;

int MaxSubArray(vector<int> &nums);

/* brute-fore, so slow */
int SolutionOne(const vector<int> &nums) {
	/* initialize max_sum with nums[0], not 0, special case nums = {1} */
	int max_sum = nums[0];	
	int cur_sum = 0;
	int vec_size = nums.size();
	for (int i = 0; i < vec_size; ++i) {
		for (int j = i; j < vec_size; ++j) {
			cur_sum = 0;
			for (int k = i; k <= j; ++k) { cur_sum += nums[k]; }
			max_sum = std::max(cur_sum, max_sum);
		}
	}
	printf("SolutionOne: %d\n", max_sum);
	return max_sum;
}

/* DP */
int SolutionTwo(const vector<int> &nums) {
	int size = nums.size();
	int max_sum = nums[0];
	int cur_sum = 0;
	for (int i = 0; i < size; ++i) {
		cur_sum = std::max(cur_sum + nums[i], nums[i]);
		max_sum = std::max(max_sum, cur_sum);
	}
	printf("SolutionTwo: %d\n", max_sum);
	return max_sum;
}

int Solution(const vector<int> &nums) {
	srand(time(NULL));
	int rand_int = rand() % 2 + 1;
	switch (rand_int) {
		case 1: return SolutionOne(nums); break;
		case 2: return SolutionTwo(nums); break;
	}
	return -1;
}

void Test53() {
	vector<int> iv;
	iv = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	Solution(iv);
}

int main() {
	Test53();
}
