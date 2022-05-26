#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_set;
using std::unordered_map;

string MostCommonWord(string paragraph,
	vector<string> banned);

string SolutionOne(string paragraph,
	vector<string> banned) {
	unordered_set<string> banned_set;
	for (auto &word : banned) {
		banned_set.emplace(word);
	}
	int max_cnt = 0;
	unordered_map<string, int> cnt;
	string word;
	int size = paragraph.size();
	for (int i = 0; i < size; ++i) {
		if (i < size && isalpha(paragraph[i])) {
			word.push_back(std::tolower(paragraph[i]));
		} else if (word.size() > 0) {
			if (!banned_set.count(word)) {
				cnt[word]++;
				max_cnt = std::max(max_cnt, cnt[word]);
			}
			word = " ";
		}
	}
	string most_common = " ";
	for (auto &[word, i_cnt] : cnt) {
		if (i_cnt == max_cnt) {
			most_common = word;
			break;
		}
	}
	return most_common;
}

string Solution(string paragraph,
	vector<string>  &banned) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(paragraph, banned);
	}
	return "";
}

void Test00859() {
	string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
	// unordered_set<string> banned;
	// banned.insert("hit");
	vector<string> banned = {"hit"};
	string res = "";
	res = Solution(paragraph, banned);
	printf("%s\n", res.c_str());
	// printf("\nend of Test00859\n");
}

int main(int argc, char **argv) {
	Test00859();
}
