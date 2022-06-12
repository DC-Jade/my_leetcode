#include <ctime>
#include <cstdio>
#include <string>
#include <vector>

using std::vector;
using std::string;

string LongestCommonPrefix(const vector<string> &strs);
string SolutionOne(const vector<string> &vstr);
string Solution(const vector<string> &vstr);

string SolutionOne(const vector<string> &vstr) {
	string max_str = vstr[0];
	int min_common_size = max_str.size();
	for (const auto str : vstr) {
		int cur_size = str.size();
		min_common_size = std::min(min_common_size, cur_size);
		if (min_common_size == 0) break;
		for (int i = 0; i < min_common_size; ++i) {
			if (max_str[i] != str[i]) {
				min_common_size = std::min(min_common_size, i);
				break;
			} else if (i == min_common_size) {
				/* case - flower, flow */
				++min_common_size;
			}
		} 
	}
	return max_str.substr(0, min_common_size);
}

string Solution(const vector<string> &vstr) {
	switch (rand() % 1) {
		default: printf("\nSolutionOne"); return SolutionOne(vstr); break;
	}
}

void Test00014() {
	srand(time(nullptr));
	vector<string> vstr = {"flower", "flow", "flight"};
	string res = Solution(vstr);
	printf("\n%s\n", res.c_str());
}

int main() {
	Test00014();
}
