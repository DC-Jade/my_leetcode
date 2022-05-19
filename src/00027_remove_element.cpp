#include <stdio.h>

#include <cstdlib>
#include <vector>
#include <ctime>

#include "../include/ivv.hpp"
using std::vector;

int RemoveElement(vector<int> &nums, int val);

int SolutionOne(vector<int> &nums, int val) {
	int slow = 0; int fast = 0;
	int size = nums.size();
	while (fast < size) {
		if (nums[fast] != val) {
			nums[slow] = nums[fast];
			++slow;
		}
		++fast;
	}
	return slow;
}

int Solution(vector<int> &nums, int val) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne: \n"); return SolutionOne(nums, val);
		// case 2:	printf("SolutionTwo: \n"); return SolutionTwo(nums, val);
	}
	return -1;
}

void Test00027() {
	int n = 0;
	int val = 2;
	vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
	n = Solution(nums, val);
	printf("%d\n", n);
	intvectorvector::PrintIV(nums, n);
}

int main(int argc, char **argv) {
	Test00027();
}
