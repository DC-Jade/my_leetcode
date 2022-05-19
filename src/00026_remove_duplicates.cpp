#include <stdio.h>

#include <cstdlib>
#include <vector>
#include <ctime>

#include "../include/ivv.hpp"
using std::vector;

int RemoveDuplicates(vector<int> &nums);

int SolutionOne(vector<int> &nums) {
	int next_pos = 0;
	int size = nums.size();
	int res_size = 0;
	int i = 0;
	while (++next_pos && next_pos < size) {
		while (next_pos < size && nums[i] == nums[next_pos]) ++next_pos;
		if (next_pos < size) nums[++i] = nums[next_pos];
		else { 
			res_size = i + 1;
			return res_size;
		}
	}
	res_size = i + 1;
	return res_size;	
}

int SolutionTwo(vector<int> &nums) {
	int size = nums.size();
	if (size == 0) return 0;
	int fast = 1; int slow = 1;
	while (fast < size) {
		if (nums[fast] == nums[fast - 1]) ++fast;
		else { nums[slow] = nums[fast]; ++slow; ++fast; }
	}
	return slow;
}

int Solution(vector<int> &nums) {
	srand(time(nullptr));
	int rand_int = rand() % 2 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne: \n"); return SolutionOne(nums);
		case 2:	printf("SolutionTwo: \n"); return SolutionTwo(nums);
	}
	return -1;
}

void Test00026() {
	int n = 0;
	vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	nums = {1, 1};
	n = Solution(nums);
	printf("%d\n", n);
	intvectorvector::PrintIV(nums, n);
}

int main(int argc, char **argv) {
	Test00026();
}
