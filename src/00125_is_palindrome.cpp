#include <cstdio>
#include <ctime>

#include <string>

using std::string;

bool IsPalindrome(const string &s);
bool SolutionOne(const string &s);
bool Solution(const string &s);

/* two pointers */
bool SolutionOne(const string &s) {
	for (int i = 0, j = s.size() - 1; i <= j; ++i, --j) {
		/* alphabetic and digit */
		// while (i <= j && !(isalpha(s[i]) || isdigit(s[i]))) ++i;
		// while (i <= j && !(isalpha(s[j]) || isdigit(s[j]))) --j;
		while (i <= j && !(isalnum(s[i]))) ++i;
		while (i <= j && !(isalnum(s[j]))) --j;
		/* case - "   " */
		if (i > j) return true;
		if (tolower(s[i]) != tolower(s[j])) return false;
	}
	return true;
}

bool SolutionTwo(const string &s) {
	string s_alnum;
	for (auto &c : s) {
		if (isalnum(c)) s_alnum.push_back(tolower(c));
	}
	string s_alnum_rev(s_alnum.rbegin(), s_alnum.rend());
	return s_alnum_rev == s_alnum;
}

bool Solution(const string &s) {
	switch (rand() % 2) {
		case 1: printf("SolutionTwo\n"); return SolutionTwo(s);
		default: printf("SolutionOne\n"); return SolutionOne(s);
	}
}

void Test00125() {
	string s = "A man, a plan, a canal: Panama";
	s = "race a car";
	// s = "   ";
	bool res = Solution(s);
	res ? printf("Is Panlindrome\n") : printf("Is not Panlindrome\n");
}

int main() {
	Test00125();
}


