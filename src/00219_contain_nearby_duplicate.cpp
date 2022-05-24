#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctime>
#include <unordered_map>

using std::vector;
using std::unordered_map;

bool ContainsNearbyDuplicate(vector<int>  &nums, int k);

/* hashtable save {val, index} */
bool SolutionOne(const vector<int>  &nums, int k) {
	unordered_map<int, int> cnt;
	// for (const auto &i : nums) {
	// for (auto pi = nums.begin(); pi != nums.end(); ++pi) {
	int size = nums.size();
	int cur_val = 0;
	decltype(cnt.end()) pre_pos;
	// int pre_pos = 0;
	for (int i = 0; i < size; ++i) {
		cur_val = nums[i];
		// auto pre_pos = cnt.find(cur_val);
		pre_pos = cnt.find(cur_val);
		// if (pre_pos != cnt.end() && (pi - pre_pos) <= k) return true;
		if (pre_pos != cnt.end() && (i - pre_pos->second) <= k) return true;
		// if (cnt[i] <= 2) return true;
		cnt[cur_val] = i;
	}
	return false;
}

/* sliding window [0, k +  O(N*k) overtime */
bool SolutionTwo(const vector<int>  &nums, int k) {
	int size = nums.size();
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < i + k + 1; ++j) {
			if (j < size && nums[i] == nums[j]) return true;
		}
	}
	return false;
}

/* sliding window O(N) replace find in Two with hashtable */
bool SolutionThree(const vector<int> &nums, int k) {
	int size = nums.size();
	unordered_map<int, int> cnt;
	int cur_val = 0;
	int remove_val = 0;
	for (int i = 0; i < size; ++i) {
		cur_val = nums[i];
		if (i > k) {
			remove_val = nums[i - k - 1];
			cnt.erase(remove_val);
		}
		if (cnt.count(cur_val) == 1) return true;
		cnt[cur_val] = i;
	}
	return false;
}

bool Solution(const vector<int>  &nums, int k) {
	srand(time(nullptr));
	int rand_int = rand() % 3 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(nums, k); break;
		case 2: printf("SolutionTwo\n"); return SolutionTwo(nums, k); break;
		case 3: printf("SolutionThree\n"); return SolutionThree(nums, k); break;
	}
	return false;
}

void Test00219() {
	vector<int> nums = {1, 2, 3, 1, 2, 3};
	bool res;
	int k = 2;
	res = Solution(nums, k);
	res ? printf("true\n") : printf("false\n");
}

int main() {
	Test00219();
}
