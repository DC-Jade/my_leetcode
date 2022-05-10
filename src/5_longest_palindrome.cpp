#include <stdio.h>

#include <string>
#include <algorithm>
#include <ctime>

using std::string;

string SolutionOne(const string &s);
string SolutionTwo(const string &s);
string Solution(const string &s);

string Solution(const string &s) {
	srand(time(NULL));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: return SolutionOne(s); break;
		case 2: return SolutionTwo(s); break;
	}
}

string longest_palindrome(const string &s) {
	Solution(s);
}

/* brute-force so slow that over-time */
string SolutionOne(const string &s) {
	int len = s.length();
	string max_str;
	string cur_str;
	string rev_cur_str;
	for (int i = 0; i < len; ++i) {
		for (int j = i; j < len; ++j) {
			cur_str = cur_str + s[j];
			rev_cur_str = cur_str;
			std::reverse(rev_cur_str.begin(), rev_cur_str.end());
			if (cur_str == rev_cur_str)
				max_str = (cur_str.length() <= max_str.length()) ? max_str : cur_str;
		}
		cur_str = "";
	}
	printf("SolutionOne: %s\n", max_str.c_str());
	return max_str;
}

/* TODO: dp */
string SolutionTwo(const string &s) {

}

void Test5() {
	string s;
	s = "aba";
	longest_palindrome(s);
}

int main() {
	Test5();
}

