#include <stdio.h>

#include <vector>
#include <string>
#include <ctime>

using std::vector;
using std::string;

vector<string> GenerateParenthesis(int n);

vector<string> Solution(int n);
vector<string> SolutionOne(int n);

void Test22();

vector<string> Solution(int n) {
	srand(time(NULL));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: return SolutionOne(n); break;
	}
}

void DFS(int n, int lc, int rc, string str, vector<string> &sv) {
	if (lc == n && rc == n) sv.push_back(str);
	else {
		if (lc < n) DFS(n, lc + 1, rc, str + "(", sv);
		if (rc < n && lc > rc) DFS(n, lc, rc + 1, str + ")", sv);
	}
}

void PrintStringVector(const vector<string> *psv) {
	for (string str : (*psv)) printf("%s\n", str.c_str());
}

vector<string> SolutionOne(int n) {
	vector<string> res_sv;
	DFS(n, 0, 0, "", res_sv);
	PrintStringVector(&res_sv);
	return res_sv;
}

/* TODO: dp */
vector<string> SolutionTwo(int n);

void Test22() {
	int n;
	while (scanf("%d", &n) != EOF) {
		Solution(n);
	}
}

int main() {
	Test22();
}
