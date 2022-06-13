#include <cstdlib>
#include <ctime>

#include <string>
#include <stack>

using std::string;
using std::stack;

bool IsValid(const string &s);
bool SolutionOne(const string &str);
bool Solution(const string &str);

bool IsPair(char c1, char c2) {
	if (c1 == ')' && c2 == '(') return true;
	if (c1 == ']' && c2 == '[') return true;
	if (c1 == '}' && c2 == '{') return true;
	return false;
}

bool SolutionOne(const string &str) {
	stack<char> sc;
	for (auto &c : str) {
		if (sc.empty() || !IsPair(c, sc.top())) sc.emplace(c);
		else if (!sc.empty()) sc.pop();
	}
	if (sc.empty()) return true;
	else return false;
}

bool Solution(const string &str) {
	switch (rand() % 1) {
		default: printf("SolutionOne\n"); return SolutionOne(str); break;
	}
}

void Test00020() {
	string s = "()";
	s = "()[]{}";
	s = "([)]";
	bool res = Solution(s);
	res ? printf("True\n") : printf("false\n");
}

int main() {
	Test00020();
}
