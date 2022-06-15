#include <cstdlib>
#include <ctime>

#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

bool WordPattern(const string &pattern, const string &s);
bool SolutionOne(const string &pattern, const string &s);
bool Solution(const string &pattern, const string &s);


vector<string> str2vstr(const string &str, vector<string> &vstr) {
	string word = "";
	for (auto &ch : str) {
		if (isalpha(ch)) word += ch;
		else { 
			vstr.push_back(word);
			word = "";
		}
	}
	/* last word */
	vstr.push_back(word);
	return vstr;
}

bool SolutionOne(const string &pattern, const string &s) {
	int length = pattern.size();
	vector<string> vstr;
	str2vstr(s, vstr);
	if (length != vstr.size()) return false;

	unordered_map<char, string> ch2str;
	unordered_map<string, char> str2ch;
	for (int i = 0; i < length; ++i) {
		char cur_ch = pattern[i];
		string cur_str = vstr[i];
		if (ch2str.find(cur_ch) == ch2str.end() &&
			str2ch.find(cur_str) == str2ch.end()) { /* both do not exist, insert */
			ch2str.insert({{cur_ch, cur_str}});
			str2ch.insert({{cur_str, cur_ch}});
		} else if (ch2str.find(cur_ch) == ch2str.end() &&
      str2ch.find(cur_str) != str2ch.end()) { 
			return false;
		} else if (ch2str.find(cur_ch) != ch2str.end() &&
			ch2str.at(cur_ch) != cur_str) {
			return false;
		} 
	}
	return true;
}

bool Solution(const string &pattern, const string &s) {
	switch (rand() % 1) {
		default: printf("SolutionOne\n"); return SolutionOne(pattern, s);
	}
}

void Test00290() {
	string pattern = "abba";
	string str = "dog cat cat dog";
	pattern = "abba"; str = "dog cat cat fish";
	bool res = Solution(pattern, str);
	res ? printf("True\n") : printf("False\n");
}

int main() {
	Test00290();
}
