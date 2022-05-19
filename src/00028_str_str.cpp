#include <stdio.h>

#include <cstdlib>
#include <string>
#include <ctime>

using std::string;

int StrStr(string haystack, string needle);

int SolutionOne(const string &s, const string &t) {
	int i = 0; int j = 0;
	int m = s.size(); int n = t.size();
	int res_pos = 0;
	/* case: empty string */
	if (n == 0) return 0;
	for (i = 0; i < m; ++i) {
		j = 0;
		if (s[i] != t[j]) continue;
		res_pos = i;
		while (i < m && j < n && s[i] == t[j]) { ++i; ++j; }
		if (j == n) return res_pos;
		i = res_pos;
	}
	return -1;
}

int Solution(string s, string t) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne: \n"); return SolutionOne(s, t);
	}
	return -1;
}

void Test00028() {
	int n = -1;
	string s = "hello"; string t = "ll";
	s = "aaaaa"; t = "bba";
	n = Solution(s, t);
	printf("%d\n", n);
}

int main(int argc, char **argv) {
	Test00028();
}
