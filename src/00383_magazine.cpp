#include <cstdio>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

bool CanConstruct(string ransom_note, string magazine);
bool SolutionOne(const string &ransom_note, const string &magazine);
bool Solution(const string &ransom_note, const string &magazine);

bool SolutionOne(const string &ransom_note, const string &magazine) {
	unordered_map<char, int> um_count;
	for (auto &ch : magazine) ++um_count[ch];
	for (auto &ch : ransom_note) {
		if (um_count.find(ch) == um_count.end()) return false;
		else {
			--um_count[ch];
			if (um_count[ch] < 0) return false;
		}
	}
	return true;
}

bool Solution(const string &ransom_note, const string &magazine) {
	switch (rand() % 1) {
		default: printf("SolutionOne\n"); return SolutionOne(ransom_note, magazine);
	}
}

void Test00383() {
	string ransom_note = "aa";
	string magazine = "ab";
	ransom_note = "aa"; magazine = "aab";;;;
	int res = Solution(ransom_note, magazine);
	res ? printf("True\n") : printf("false\n");
}

int main() {
	Test00383();
}
