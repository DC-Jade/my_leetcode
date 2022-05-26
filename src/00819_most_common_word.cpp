#include <cstdlib>
#include <cstdio>
#include <ctime>

#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;

string MostCommonWord(string paragraph, vector<string> &banned);

string SolutionOne(string &paragraph, const vector<string> &banned) {
	unordered_set<string> banned_set;
	for (const auto &s : banned) { banned_set.emplace(s); }

	/* append a empty ' ' */
	paragraph.push_back(' ');
	int size = paragraph.size();
	unordered_map<string, int> cnt;
	int max_cnt = 0;
	string word = "";
	string max_string = "";
	
	// string max_string = "";
	for (int i = 0; i < size; ++i) {
		char cur_char = paragraph[i];
		if (std::isalpha(cur_char)) { word.push_back(std::tolower(cur_char)); }
		else if (word.size() > 0){
			if (banned_set.count(word) == 0) {
				++cnt[word];
				if (max_cnt < cnt[word]) {
					max_cnt = cnt[word];
					max_string = word;
				}
			}
			word.erase();
		}
	}
	return max_string;
}

string SolutionTwo(string &paragraph, const vector<string> &banned) {
	unordered_set<string> banned_set;
	for (const auto &s : banned) banned_set.emplace(s);

	paragraph.push_back(' ');
	unordered_map<string, int> cnt;
	int size = paragraph.size();
	string word = "";
	for (int i = 0; i < size; ++i) {
		char cur_char = paragraph[i];
		if (std::isalpha(cur_char)) { word.push_back(std::tolower(cur_char)); }
		else {
			if (banned_set.count(word) == 0) { ++cnt[word]; }
			word.erase();
		}
	}
	/* find max cnt */
	string max_word = "";
	int max_cnt = 0;
	for (auto it = cnt.begin(); it != cnt.end(); ++it) {
		if (it->second > max_cnt) { max_cnt = it->second; max_word = it->first; }
	}
	return max_word;
}

string Solution(string &paragraph, const vector<string> &banned) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 2;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(paragraph, banned);
		case 2: printf("SolutionTwo\n"); return SolutionTwo(paragraph, banned);
	}
	return "";
}

void Test00819() {
	string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
	vector<string> banned = {"hit"};
	// string paragraph = "Bob";
	// vector<string> banned = {""};
	string res = Solution(paragraph, banned);
	printf("%s\n", res.c_str());
}

int main() {
	Test00819();
}

