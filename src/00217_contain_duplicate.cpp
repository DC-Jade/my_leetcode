#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctime>
#include <unordered_map>

using std::vector;
using std::unordered_map;

bool ContainsDuplicate(vector<int> &nums);

bool SolutionOne(const vector<int> &nums) {
	unordered_map<int, int> cnt;
	for (const auto &i : nums) {
		++cnt[i];
		if (cnt[i] >= 2) return true;
	}
	return false;
}

bool SolutionTwo(const vector<int> &nums) {
	unordered_map<int, int> cnt;
	for (const auto &i : nums) {
		if (cnt.count(i) == 1) return true;
		++cnt[i];
	}
	return false;
}

bool Solution(const vector<int> &nums) {
	srand(time(nullptr));
	int rand_int = rand() % 2 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(nums); break;
		case 2: printf("SolutionTwo\n"); return SolutionTwo(nums); break;
	}
	return false;
}

void Test00217() {
	vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
	bool res;
	res = Solution(nums);
	res ? printf("true\n") : printf("false");
}

int main() {
	Test00217();
}
