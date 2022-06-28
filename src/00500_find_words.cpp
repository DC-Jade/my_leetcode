#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_set;

vector<string> FindWords(vector<string> &words);
vector<string> SolutionOne(const vector<string> &words);
vector<string> Solution(const vector<string> &words);

vector<unordered_set<char>> keywords = {
	{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
	{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
	{'z', 'x', 'c', 'v', 'b', 'n', 'm'}
};

bool IsKeyword(const string &str, const vector<unordered_set<char>> &keywords) {

	for (const auto &keyword : keywords) {
		if (keyword.find(tolower(str[0])) == keyword.end()) { 
			continue;
		}
		for (const auto &ch : str) { 
			if (keyword.find(tolower(ch)) == keyword.end()) return false;
		}
		return true;
	}
	return false;
}

vector<string> SolutionOne(const vector<string> &words) {
	vector<string> res;
	for (const auto &word : words) {
		if (IsKeyword(word, keywords)) res.push_back(word);
	}
	return res;
}

vector<string> Solution(const vector<string> &words) {
	switch (rand() % 1) {
		default: printf("SolutionOne\n"); return SolutionOne(words);
	}
}

void Test00500() {
	vector<string> words = { "adsdf", "sfd" };
	// words = {"omk"};
	// words = {"Hello", "Alaska", "Dad", "Peace"};
	vector<string> res = Solution(words);
	for (const auto &str : res) { printf("%s\n", str.c_str()); }
}

int main() {
	Test00500();
}

