#include <stdio.h>
#include <assert.h>

#include <vector>

using std::vector;

int MinCostClimbingStairs(vector<int> &cost);

/* DP */
int SolutionOne(vector<int> &cost) {
	int len = cost.size();
	int res = 0;
	vector<int> iv(len + 1, 0);
	
	/* base case */
	iv[0] = 0;
	iv[1] = 0;

	for (int i = 2; i < len + 1; ++i) {
		assert(&(iv[i - 2]) != nullptr);
		iv[i] = std::min(iv[i - 1] + cost[i - 1], iv[i - 2] + cost[i - 2]);
	}
	assert(&(iv[len]) != nullptr);
	res = iv[len];
	printf("%d\n", res);
	return res;
}

void Test746() {
	vector<int> cost = {10, 15, 20};
	SolutionOne(cost);
}

int main(int argc, char **argv) {
	Test746();
}
