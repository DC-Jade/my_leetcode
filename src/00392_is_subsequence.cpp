#include <stdio.h>

#include <cstdlib>
#include <string>

using std::string;

bool IsSubsequence(const string &s, const string &t);

bool SolutionOne(const string &s, const string &t) {
	int m = s.size(); int n = t.size();
	int i = 0; int j = 0;
	while (i < m && j < n) {
		if (s[i] == t[j]) { ++i; ++j; }
		else ++j;
	}
	return i == m;
}

bool Solution(const string &s, const string &t) {
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: return SolutionOne(s, t); break;
	}
	return -1;
}

void Test00392() {
	string s = "abc"; string t = "ahbgdc";
	s = "axc", t = "ahbgdc";
	Solution(s, t) ? printf("true\n") : printf("false\n");
	printf("end of Test00392\n");
}

int main() {
	Test00392();
}
