#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>

#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;
using std::unordered_map;

bool IsAnagram(string s, string t);

/* sort and compare O(NlogN) */
bool SolutionOne(string &s, string &t) {
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());
	int s_size = s.size();
	int t_size = t.size();
	if (s_size != t_size) return false;
	for (int i = 0; i < s_size; ++i) {
		if (s[i] != t[i]) return false;
	}
	return true;
}


/* hashtable save count O(N) */
bool SolutionTwo(string &s, string &t) {
	unordered_map<char, int> s_cnt;
	unordered_map<char, int> t_cnt;
	int s_size = s.size();
	int t_size = t.size();
	if (s_size != t_size) return false;

	for (int i = 0; i < s_size; ++i) {
		++s_cnt[s[i]];
	}
	for (int j = 0; j < t_size; ++j) {
		++t_cnt[t[j]];
	}
	for (int k = 0; k < s_size; ++k) {
		if (s_cnt[s[k]] != t_cnt[s[k]]) return false;
	}
	return true;
}

bool SolutionThree(string &s, string &t) {
	unordered_map<char, int> cnt;
	// unordered_map<char, int> t_cnt;
	int s_size = s.size();
	int t_size = t.size();
	if (s_size != t_size) return false;

	for (int i = 0; i < s_size; ++i) {
		++cnt[s[i]];
	}
	for (int j = 0; j < t_size; ++j) {
		if(cnt.count(t[j]) == 0) return false;
		--cnt[t[j]];
		if (cnt[t[j]] < 0) return false;
	}
	return true;
}

/* replace hashtable with vector */
bool SolutionFour(string &s, string &t) {
	int chr_size = 26;
	vector<int> iv(chr_size, 0);
	int s_size = s.size();
	int t_size = t.size();
	if (s_size != t_size) return false;
	for (int i = 0; i < s_size; ++i) {
		++iv[s[i] - 'a'];
	}
	for (int j = 0; j < t_size; ++j) {
		--iv[t[j] - 'a'];
		if (iv[t[j] - 'a'] < 0) return false;
	}
	return true;
}

bool Solution(string &s, string &t) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 4;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(s, t); break;
		case 2: printf("SolutionTwo\n"); return SolutionTwo(s, t); break;
		case 3: printf("SolutionThree\n"); return SolutionThree(s, t); break;
		case 4: printf("SolutionFour\n"); return SolutionFour(s, t); break;
	}
	return false;
}

void Test_00242() {
	string s = "anagram";
	string t = "nagaram";
	bool res = false;
	res = Solution(s, t);
	res ? printf("True\n") : printf("False\n");
}

int main(int argc, char **argv) {
	Test_00242();
}
