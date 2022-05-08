#include <assert.h>

#include <string>
#include <vector>

#include "../include/read_ordinary_string_file.hpp"

string SolutionOne(const string &s, const int &n) {
	string tmp;
	tmp = s.substr(n, s.length()) + s.substr(0, n);
	return tmp;
}

string SolutionTwo(const string &s, const int &n) {
	return s.substr(n, s.length()) + s.substr(0, n);
}

string SolutionThree(const string &s, const int &n) {
	/* targer string = s[n, len - n] + s[len, n] */
	string tmp = s;
	int len = s.length();
	/* dupliate tmp */
	tmp += tmp;
	return tmp.substr(n, len - n) + tmp.substr(len, n);
}

string ReverseLeftWords(const string &s, const int &n) {
	return SolutionThree(s, n);
}

void Test58() {
	vector<string> vec_str;
	int n = getchar() - '0';	/* need convert ASCII to int, or get ASCII value */
	assert(n >= 0 && n <= 9);
	string str, tmp;

	ReadOrdinaryStringFile(&vec_str);
	for (auto str : vec_str) {
		tmp = ReverseLeftWords(str, n);
		printf("%s\n", tmp.c_str());
		tmp = "";
	}
}

int main(int argv, char *argc[]) {
	Test58();
}



