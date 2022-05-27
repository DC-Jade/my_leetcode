#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>

#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

char FindTheDifference(string &s, string &t);

char SolutionOne(string &s, string &t) {
	/* keep s.size() < t.size(); */
	if (s.size() > t.size()) return SolutionOne(t, s);

	/* save longer string */
	unordered_map<char, int> cnt;
	for (const auto &c : s) ++cnt[c];
	
	/* find cnt not equal element */
	std::sort(t.begin(), t.end());
	int t_size = t.size();
	int cur_cnt = 0;
	for (int i = 0; i < t_size; ++i) {
		char cur_val = t[i];
		cur_cnt = 0;
		while (i < t_size - 1 && cur_val == t[i + 1]) { ++i; ++cur_cnt; }
		++cur_cnt;
		if (cnt.count(cur_val) == 0) { return cur_val; }
		else if (cnt.at(cur_val) != cur_cnt) { return cur_val; }
	}
	return ' ';
}

/* count and minus, default - t > s */
char SolutionTwo(string &s, string &t) {
	vector<int> cnt(26, 0);
	for (const auto &c : s) ++cnt[c - 'a'];
	for (const auto &c : t) {
		if (cnt[c - 'a'] > 0)  --cnt[c - 'a'];
		else return c;
	}
	return ' ';
}

/* bit operation, xor */
char SolutionThree(string &s, string &t) {
	int res = 0;
	for (auto &c : s) res ^= c;
	for (auto &c : t) res ^= c;
	// printf("%d\n", res);
	return (char)res;
}

/* t - s */
char SolutionFour(string &s, string &t) {
	int sum = 0;
	for (const auto &c : t) sum += (int)c;
	for (const auto &c : s) sum -= (int)c;
	return (char)sum;
}

char Solution(string &s, string &t) {
	srand(time(nullptr));
	int rand_int = rand() % 4 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(s, t); break;
		case 2: printf("SolutionTwo\n"); return SolutionTwo(s, t); break;
		case 3: printf("SolutionThree\n"); return SolutionThree(s, t); break;
		case 4: printf("SolutionFour\n"); return SolutionFour(s, t); break;
	}
	return ' ';
}

void Test00389() {
	string s = "abcd";
	string t = "abcde";
	s = "";
	t = "y";
	char res = Solution(s, t);
	printf("%c\n", res);
}

int main() {
	Test00389();
}
