#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

#include "../include/ivv.hpp"

using std::vector;

void SolutionOne(vector<int> &nums);
void SolutionTwo(vector<int> &nums);
void Solution(vector<int> &nums);

void Solution(vector<int> &nums) {
	srand(time(NULL));
	int rand_int = rand() % 2 + 2;
	switch (rand_int) {
		case 1: SolutionOne(nums); break;
		case 2: SolutionTwo(nums); break;
	}
}

void MoveZeros(vector<int> &nums) {
	Solution(nums);
}

void Move(vector<int> &nums, int zero_pos, const int &tar_pos) {
	/* move zero element from zero_pos to tar_pos */
	int next_pos = 0;
	while (zero_pos < tar_pos) {
		next_pos = zero_pos + 1;
		std::swap(nums[zero_pos], nums[next_pos]);
		zero_pos = next_pos;
	}
}

void SolutionOne(vector<int> &nums) {
	int size = nums.size();
	int cur_pos = size - 1;
	for (int i = size - 1; i > -1; --i) {
		if (nums[i] == 0) {
			Move(nums, i, cur_pos);
			--cur_pos;
		}
	}
}

/*  */
void SolutionTwo(vector<int> &nums) {
	int left = 0; int right = 0;
	int size = nums.size();
	while (right < size) {
		if (nums[right] != 0) {
			std::swap(nums[left], nums[right]);
			++left;
		}
		++right;
	}
}

void Test00283() {
	vector<int> nums = {0, 1, 0, 3, 12};
	// vector<int> nums = {0};
	int size = nums.size();
	Solution(nums);
	intvectorvector::PrintIV(nums, size);
}

int main() {
	Test00283();
}

