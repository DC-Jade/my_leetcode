#include <stdio.h>

#include <vector>

#include "../include/ivv.hpp"

using std::vector;
using intvectorvector::InitializeIVV;
using intvectorvector::PrintIV;

int MaxProfit(vector<int> &prices, int fee);

int SolutionOne(vector<int> &prices, int fee) {
	vector<vector<int>> ivv;
	int day = prices.size();
	InitializeIVV(ivv, day, 2);
	int res = 0;
	ivv[0][0] = 0;
	ivv[0][1] = -prices[0];
	
	for (int i = 1; i < day; ++i) {
		ivv[i][0] = std::max((ivv[i - 1][0]), (ivv[i - 1][1] - fee + prices[i]));
		ivv[i][1] = std::max((ivv[i - 1][0] - prices[i]), (ivv[i - 1][1]));
	}
	res = std::max(ivv[day - 1][0], ivv[day - 1][1]);
	printf("%d\n", res);
	return res;
}

void Test714() {
	vector<int> prices = {1, 3, 2, 8, 4, 9};
	int fee = 2;
	SolutionOne(prices, fee);
}

int main() {
	Test714();
}
