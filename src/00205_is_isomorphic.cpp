#include <cstdio>
#include <cstdlib>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

bool IsIsomorphic(string &s, string &t);

bool SolutionOne(const string &s, const string &t) {
	unordered_map<char, char> s2t;
	unordered_map<char, char> t2s;
	int s_size = s.size();
	int t_size = t.size();
	if (s_size != t_size) return false;
	for (int i = 0; i < s_size; ++i) {
		char s_chr = s[i];
		char t_chr = t[i];
		auto it = s2t.find(s_chr);
		auto it_t = t2s.find(t_chr);

		if (it != s2t.end()) 
			if (it->second == t_chr) continue;
			else return false;
		if (it_t != t2s.end()) {
			if (it_t->second == s_chr) continue;
			else return false;
		}
		s2t[s_chr] = t_chr;
		t2s[t_chr] = s_chr;
	}
	return true;
}

bool Solution(const string &s, const string &t) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(s, t); break;
	}
	return false;
}

void Test00205() {
	string s = "paper";
	string t = "title";
	bool res;
	res = Solution(s, t);
	res ? printf("true\n") : printf("false\n");
}

int main() {
	Test00205();
}
