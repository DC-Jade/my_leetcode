#include <cstdio>
#include <ctime>

#include <string>

using std::string;

bool DetectCapitalUse(string word);
bool SolutionOne(const string &word);
bool SolutionTwo(const string &word);
bool Solution(const string &word);

bool SolutionOne(const string &word) {
	if (isupper(word.at(0))) {
		int i = 1;
		while (i < word.size() && isupper(word.at(i))) ++i;
		if (i == word.size()) return true;
		else if (i != 1) return false;
		else  {
			while (i < word.size() && islower(word.at(i))) {
				++i;
			}
			if (i == word.size()) return true;
			else return false;
		}
	} else { /* TODO: all lower case - leetcode */
		for (const auto &ch : word) {
			if (isupper(ch)) return false;
		}
		return true;
	}
}

bool SolutionTwo(const string &word) {
	if (word.size() >= 2 && islower(word.at(0)) && isupper(word.at(1)))
		return false;
	int i = 2;
	while (i < word.size()) {
		// if (islower(word.at(i - 1)) && islower(word.at(i))) ++i;
		// else if (isupper(word.at(i - 1)) && isupper(word.at(i))) ++i;
		// else return false;
		/* alternative to upper three lines */
		if (islower(word.at(i - 1)) ^ islower(word.at(i))) return false;
		++i;
	} 
	return true;
}

bool Solution(const string &word) {
	switch (rand() % 2) {
		case 1: printf("SolutionTwo\n"); return SolutionTwo(word);
		default: printf("SolutionOne\n"); return SolutionOne(word);
	}
}

void Test00520() {
	srand(time(nullptr));
	string word = "USA";
	word = "FlaG";
	word = "leetcode";
	bool res = Solution(word);
	res ? printf("True\n") : printf("false\n");
}

int main() {
	Test00520();
}
