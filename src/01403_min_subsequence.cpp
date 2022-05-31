#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <vector>

using std::vector;

vector<int> MinSubsequence(vector<int> &nums);
vector<int> SolutionOne(vector<int> &nums);
vector<int> Soultion(vector<int> &nums);

/* greedy */
bool Compare(const int &lhs, const int &rhs) {
	return lhs > rhs;
}

vector<int> SolutionOne(vector<int> &nums) {
	// std::sort(nums.begin(), nums.end(), Compare);
	std::sort(nums.begin(), nums.end(), [] (int x, int y) {
		return x > y;
  });

	int left = 0;
	for (const auto &i : nums) left += i;

	int sum = 0;
	vector<int> res;
	for (const auto &i : nums) {
		res.emplace_back(i);
		sum += i;
		left -= i;
		// if (left < sum) return res;
		if (left < sum) break;
	}
	return res;
}

vector<int> Solution(vector<int> &nums) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(nums); break;
	}
	return {0};
}

void Test01403() {
	vector<int> nums = {4, 3, 10, 9, 8};
	nums = {6};
	nums = {4, 4, 7, 6, 7};
	vector<int> res = Solution(nums);
	for (const auto i : res) { printf("%d ", i); }
	printf("\nend of Test01403\n");
}

int main(int argc, char **argv) {
	Test01403();
}
