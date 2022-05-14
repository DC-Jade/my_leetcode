#include <stdio.h>
#include <assert.h>

#include <vector>

using std::vector;

int MinCostClimbingStairs(vector<int> &cost);

/* TODO: DP */
int SolutionOne(vector<int> &cost) {
	int len = cost.size();
	int res = 0;
	vector<int> iv(len, 0);
	
	/* base case */
	iv[0] = cost[0];
	iv[1] = cost[1];

	for (int i = 2; i < len; ++i) {
		assert(&(iv[i - 2]) != nullptr);
		iv[i] = std::min(iv[i - 1] + cost[i], iv[i - 2]);
	}
	// assert(&(iv[len - 1]) != nullptr);
	res = std::min(iv[len - 1], iv[len - 2]);
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
