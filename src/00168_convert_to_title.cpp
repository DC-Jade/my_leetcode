#include <cstdio>
#include <ctime>
#include <algorithm>

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

string ConverToTitle(int columnNumber);
string SolutionOne(int column_number);
string Solution(int colunm_number);

string SolutionOne(int column_number) {
	int residual = column_number;
	string res;
	while (residual) {
		char cur_char = (residual - 1) % 26 + 65;
		res.push_back(cur_char);
		residual =  (residual - 1) / 26;
	}
	reverse(res.begin(), res.end());
	return res;
}

string Solution(int column_number) {
	switch (rand() % 1) {
		default: printf("SolutionOne\n"); return SolutionOne(column_number); break;
	}
}

void Test00168() {
	int n = 1;
	n = 28;
	n = 701;
	string res = Solution(n);
	printf("%s\n", res.c_str());
}

int main() {
	Test00168();
}
