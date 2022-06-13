#include <ctime>
#include <cstdio>
#include <string>
#include <vector>

using std::vector;
using std::string;

string LongestCommonPrefix(const vector<string> &strs);
string SolutionOne(const vector<string> &strs);
string SolutionTwo(const vector<string> &strs);
string SolutionThree(const vector<string> &strs);
string Solution(const vector<string> &strs);

string SolutionOne(const vector<string> &strs) {
	string max_str = strs[0];
	int min_common_size = max_str.size();
	for (const auto str : strs) {
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

static string OtherLongestCommonPrefix(const string &str1, const string &str2) {
	int min_str_size = std::min(str1.size(), str2.size());
	int common_size = 0;
	for (int i = 0; i < min_str_size && str1[i] == str2[i]; ++i) {
		++common_size;
	}
	return str1.substr(0, common_size);
}

static string MyLongestCommonPrefix(const string &str1, const string &str2) {
	int size_str1 = str1.size();
	int size_str2 = str2.size();
	int min_str_size = std::min(size_str1, size_str2);
	int min_common_size = min_str_size;
	for (int i = 0; i < min_str_size; ++i) {
		if (str1[i] != str2[i]) {
			min_common_size = std::min(min_common_size, i);
			break;
		}
		else if (i == min_str_size) min_common_size = min_str_size;
	}
	return str1.substr(0, min_common_size);
}

static string LongestCommonPrefix(const string &str1, const string &str2) {
	switch (rand() % 2) {
		case 1: return MyLongestCommonPrefix(str1, str2); break;
		default: return OtherLongestCommonPrefix(str1, str2); break;
	}
}

string SolutionTwo(const vector<string> &strs) {
	/* case - empty */
	int size = strs.size();
	if (!size) return "";
	string prefix = strs[0];
	for (int i = 1; i < size; ++i) {
		prefix = LongestCommonPrefix(prefix, strs[i]);
		if (!prefix.size()) break;
	}
	return prefix;
}

/* scan from vectical char */
string SolutionThree(const vector<string> &strs) {
	int str_count = strs.size();
	if (!str_count) return "";
	string str = strs[0];
	int max_size = str.size();
	for (int i = 0; i < max_size; ++i) {
		char cur_char = str[i];
		for (int k = 1; k < str_count; ++k) {
			if (i >= (int) strs[k].size() || cur_char != strs[k][i])
				return str.substr(0, i);
		}
	}
	return str;
}

string Solution(const vector<string> &strs) {
	switch (rand() % 3) {
		case 1: printf("\nSolutionTwo"); return SolutionTwo(strs); break;
		case 2: printf("\nSolutionThree"); return SolutionThree(strs); break;
		default: printf("\nSolutionOne"); return SolutionOne(strs); break;
	}
}

void Test00014() {
	srand(time(nullptr));
	vector<string> strs = {"flower", "flow", "flight"};
	string res = Solution(strs);
	printf("\n%s\n", res.c_str());
}

int main() {
	Test00014();
}
