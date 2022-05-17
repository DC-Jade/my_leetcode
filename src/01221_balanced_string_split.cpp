#include <stdio.h>

#include <cstdlib>
#include <vector>
#include <string>

using std::vector;
using std::string;

int BalancedStringSplit(const string &s);

int SolutionOne(const string &s) {
	int res = 0;
	int cur_count = 0;
	for (const auto &c : s) {
		(c == 'L') ? ++cur_count : --cur_count;
		if (cur_count == 0) ++res;
	}
	return res;
}

int Solution(const string &s) {
	return SolutionOne(s);
}

void Test01221() {
	int res = 0;
	string s = "RLRRLLRLRL";
	res = Solution(s);
	printf("%d\n", res);
}

int main() {
	Test01221();
}
