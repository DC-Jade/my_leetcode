#include <cstdio>
#include <string>

using std::string;

int CountSegments(string s);
int SolutionOne(const string &s);
int Solution(const string &s);

int SolutionOne(const string &s) {
	int len = s.size();
	int count = 0;
	for (int i = 0; i < len; ++i) {
		if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') ++count;
	}
	return count;
}

int Solution(const string &s) {
	switch (rand() % 1) {
		default: printf("SolutionOne\n"); return SolutionOne(s);
	}
}

void Test00434() {
	string str = "Hello, my name is John";
	str = "   ";
	str = "";
	int res = Solution(str);
	printf("%d\n", res);
}

int main() {
	Test00434();
}
