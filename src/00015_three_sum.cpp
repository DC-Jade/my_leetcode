#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

#include "../include/ivv.hpp"

using std::vector;

vector<vector<int>> ThreeSum(const vector<int> &nums);

vector<vector<int>> SolutionOne(vector<int> &nums) {
	vector<vector<int>> res_ivv;
	std::sort(nums.begin(), nums.end());
	int size = nums.size();
	for (int i = 0; i < size; ++i) {
		if (i > 0 && nums[i] == nums[i - 1]) continue;  
		int k = size - 1;
		for (int j = i + 1; j < size; ++j) {
			if (j > i + 1 && nums[j] == nums[j - 1]) continue; 
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] > 0)  { --k; }
				else break;
			}
			if (j == k) break;
			if (nums[i] + nums[j] + nums[k] == 0)
				res_ivv.push_back({nums[i], nums[j], nums[k]});
		}
	}
	intvectorvector::PrintIVV(res_ivv);
	return res_ivv;
}

vector<vector<int>> Solution(vector<int> &iv) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne: \n"); return SolutionOne(iv);
	}
	return {{0}};
}

void Test00015() {
	vector<int> iv = {-1, 0, 1, 2, -1, -4};
	Solution(iv);
}

int main(int argc, char **argv) {
	Test00015();
}
