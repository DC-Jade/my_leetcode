#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

vector<int> Intersect(vector<int> &nums1, vector<int> &nums2);

vector<int> SolutionOne(vector<int> &nums1, vector<int> &nums2) {
	unordered_map<int, int> min_cnt;
	for (int i = 0; i < nums1.size(); ++i) {
		++min_cnt[nums1[i]];
	}

	std::sort(nums2.begin(), nums2.end());
	int cur_cnt = 0;
	int cur_val = 0;
	int nums2_size = nums2.size();
	
	/* rm in min_cnt but not exist in  nums2 */
	unordered_map<int, int> nums2_cnt;
	for (int j = 0; j < nums2_size; ++j) {
		++nums2_cnt[nums2[j]];
	}
	for (auto it = min_cnt.begin(); it != min_cnt.end(); ++it) {
		if (nums2_cnt.count(it->first) == 0) min_cnt.erase(it->first);
	}

	for (int j = 0; j < nums2_size; ++j) {
		cur_val = nums2[j];
		while (j < nums2_size - 1 && nums2[j + 1] == cur_val)  { ++j; ++cur_cnt; }
		++cur_cnt;
		if (min_cnt.count(cur_val) == 0) min_cnt.erase(cur_val);
		// else if (min_cnt.count(cur_val) > cur_cnt)  {
		// else if (min_cnt.count(cur_val) > cur_cnt) {
		else if (min_cnt[cur_val] > cur_cnt) {
			min_cnt[cur_val] = cur_cnt;
		}
		cur_cnt = 0;
	}

	vector<int> res;
	/* something wrong */
	for (auto it = min_cnt.begin(); it != min_cnt.end(); ++it) {
		for (int i = it->second; i > 0; --i) res.emplace_back(it->first);
	}
	return res;
}

vector<int> SolutionTwo(vector<int> &nums1, vector<int> &nums2) {
	/*  keep nums1 < nums2 */
	if (nums1.size() > nums2.size()) return SolutionTwo(nums2, nums1);

	unordered_map<int, int> cnt;
	for (const auto &num : nums1) ++cnt[num];

	vector<int> intersection;
	for (int num : nums2) {
		if (cnt.count(num)) {
			intersection.push_back(num);
			--cnt[num];
			if (cnt[num] == 0) { cnt.erase(num); }
		}
	}
	return intersection;
}

vector<int> Solution(vector<int> &nums1, vector<int> &nums2) {
	srand(time(nullptr));
	int rand_int = rand() % 2 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(nums1, nums2); break;
		case 2: printf("SolutionTwo\n"); return SolutionTwo(nums1, nums2); break;
	}
	return {0};
}

void Test00350() {
	vector<int> nums1 = {1, 2, 2, 1};
	vector<int> nums2 = {2, 2};
	nums1 = {4, 9, 5};
	nums2 = {9, 4, 9, 8, 4};
	vector<int> res = Solution(nums1, nums2);
	for (auto &i : res) printf("%d ", i);
	printf("\nend of Test00350\n");
}

int main() {
	Test00350();
}
