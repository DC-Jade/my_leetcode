#include <stdio.h>

#include <vector>
#include <string>
#include "../include/ivv.hpp"
using std::vector; using std::string;
using intvectorvector::PrintIV;

vector<int> DiffWaysToCompute(string expression);

/* recursion */
int Caculate(const int &lhs, const int &rhs, const int &op) {
	switch (op) {
		case '+': return lhs + rhs; break;
		case '-': return lhs - rhs; break;
		case '*': return lhs * rhs; break;
	}
	return 0;
}

vector<int> SolutionOne(string expression) {
	vector<int> way;
	int len = expression.size();

	/* trival base */
	if (len == 1 || len == 2) {
		way.push_back(stoi(expression));
		return way;
	} 

	for (int i = 0; i < len; ++i) {
		int op = expression[i];
		if (op == '+' || op == '-' || op == '*') {
			vector<int> left_way = SolutionOne(expression.substr(0, i));
			vector<int> right_way = SolutionOne(expression.substr(i + 1));
			for (auto l : left_way) {
				for (auto r : right_way) {
					way.push_back(Caculate(l, r, op));
				}
			}
		}
	}
	return way;
}

void Test241() {
	vector<int> iv;
	string expression = "2-1-1";
	expression = "2*3-4*5";
	iv = SolutionOne(expression);
	PrintIV(iv);
}

int main(int argc, char **argv) {
	Test241();
}
