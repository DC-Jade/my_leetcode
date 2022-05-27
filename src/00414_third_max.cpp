#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>

#include <vector>

using std::vector;

int ThirdMax(vector<int> &nums);

int SolutionOne(vector<int> &nums) {
	std::sort(nums.begin(), nums.end(), [](int x, int y) {
		return x > y;
	});

	if (nums.size() <= 1) return nums.front();
	for (int i = 1, res = 1; i < nums.size(); ++i) {
		if (nums[i] != nums[i - 1]) { ++res; }
		if (res == 3) return nums[i];
	}
	return nums.front();
}

int Solution(vector<int> &nums) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(nums); break;
	}
	return ' ';
}

void Test00414() {
	vector<int> nums = {4,1,2,1,2};
	int res = Solution(nums);
	printf("%d\n", res);
}

int main() {
	Test00414();
}
