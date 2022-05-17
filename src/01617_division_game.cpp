#include <stdio.h>

#include <cstdlib>
#include <vector>

using std::vector;

bool DivisionGame(vector<int> &iv);


int SolutionOne(vector<int> &iv) {
	int sum = 0; int res = iv[0];
	for (int i : iv) {
		sum = std::max(sum + i, i);
		res = std::max(sum, res);
	}
	return res;
}

void Test01617() {
	int res;
	vector<int> iv = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	res = SolutionOne(iv);
	printf("%d\n", res);
}

int main() {
	Test01617();
}
