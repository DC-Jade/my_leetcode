#include <cstdio>
#include <ctime>
#include <string>

using std::string;

int LengthOfLastWord(const string &s);
int SolutionOne(const string &s);
int Solution(const string &s);

int SolutionOne(const string &s) {
	int size = s.size();
	while (size >= 0 && s[--size] == ' ') continue;
	int len = 0;
	while (size >= 0 && s[size--] != ' ') {
		++len;
	}
	return len;
}

int Solution(const string &s) {
	switch (rand() % 1) {
		default: printf("SolutionOne\n"); return SolutionOne(s); break;
	}
}

void Test00058() {
	string s = " fly me to the moon  ";
	s = "luffy is still joyboy";
	int res = Solution(s);
	printf("%d\n", res);
}

int main() {
	Test00058();
}
