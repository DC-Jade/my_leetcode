#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "../include/ivv.hpp"

using std::vector;
using std::unordered_map;

vector<int> TwoSum(vector<int> &nums, int target);

/* two pointer O(N) */
vector<int> SolutionOne(vector<int> &nums, const int &target) {
	vector<int> raw_nums = nums;
	std::sort(nums.begin(), nums.end());
	int size = nums.size();
	int lhs = 0;
	int rhs = size - 1;
	int cur_val = 0;
	vector<int> res_iv;
	while (lhs < rhs) {
		cur_val = nums[lhs] + nums[rhs];
		if (cur_val > target) { --rhs; continue; }
		if (cur_val < target) { ++lhs; continue; }
		if (cur_val == target) { 
			int lhs_index = std::find(raw_nums.begin(), raw_nums.end(), nums[lhs]) - raw_nums.begin();
			/* reverse find, find last index */
		  int rhs_index = raw_nums.rend() - std::find(raw_nums.rbegin(), raw_nums.rend(), nums[rhs]) - 1;
			res_iv.push_back(lhs_index);
			res_iv.push_back(rhs_index);
			break;
		}
	}
	return res_iv;
}

/* hashtable O(N) */
vector<int> SolutionTwo(vector<int> &nums, int target) {
	unordered_map<int, int> hashtable;
	int size = nums.size();
	for (int i = 0; i < size; ++i) {
		auto it = hashtable.find(target - nums[i]);
		if (it != hashtable.end()) { return {it->second, i}; };
		hashtable[nums[i]] = i;
	}
	return {};
}

vector<int> Solution(vector<int> &nums, const int &target) {
	srand(time(nullptr));
	int rand_int = rand() % 2 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne:\n"); return SolutionOne(nums, target);
		case 2: printf("SolutionTwo:\n"); return SolutionTwo(nums, target);
	}
	return {0};
}

void Test00001() {
	// vector<int> iv = {2, 7, 11, 15};
	vector<int> iv = {3, 2, 4};
	vector<int> res_iv;
	int target = 6;
	res_iv = Solution(iv, target);
	intvectorvector::PrintIV(res_iv, 2);
}

int main(int argc, char **argv) {
	Test00001();
}

