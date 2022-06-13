#include <cstdlib>
#include <ctime>

#include <string>
#include <stack>
#include <unordered_map>

using std::string;
using std::stack;
using std::unordered_map;

bool IsValid(const string &s);
bool SolutionOne(const string &str);
bool Solution(const string &str);

bool IsPairOne(const char &c1, const char &c2) {
	/* c1 - cur char */
	/* c2 - pop char */
	if (c1 == ')' && c2 == '(') return true;
	if (c1 == ']' && c2 == '[') return true;
	if (c1 == '}' && c2 == '{') return true;
	return false;
}

unordered_map<char, char> pairs = {
	{')', '('},
	{']', '['},
	{'}', '{'},
};

bool IsPairTwo(const char &c1, const char &c2) {
	/* c1 - cur char */
	/* c2 - pop char */
	return pairs[c1] == c2;
}

bool IsPair(const char &c1, const char &c2) {
	switch (rand() % 2) {
		case 1: printf("IsPairTwo\n"); return IsPairTwo(c1, c2);
		default: printf("IsPairOne\n"); return IsPairOne(c1, c2);
	}
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
