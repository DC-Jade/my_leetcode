#include <stdio.h>

#include <cstdlib>
#include <vector>
#include <ctime>
#include <stack>

using std::vector;
using std::stack;

int MaxProfit(vector<int> &prices);

/* so slow that time out */
int SolutionOne(vector<int> &prices) {
	int cur_profit = 0; int max_profit = 0;
	int size = prices.size();
	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size; ++j) {
			cur_profit = prices[j] - prices[i];
			max_profit = std::max(cur_profit, max_profit);
		}
	}
	printf("SolutioneOne: max profit = %d\n", max_profit);
	return max_profit;
}

/* skip some instances base on SolutioneOne, but so slow that time out */
int SolutionTwo(vector<int> prices) {
	int cur_profit= 0; int max_profit = 0;
	int size = prices.size();
	for (int i = 0; i < size; ++i) {
		if (i < size - 1 && prices[i] >= prices[i + 1]) continue;
		for (int j = i; j < size; ++j) {
			cur_profit = prices[j] - prices[i];
			max_profit = std::max(cur_profit, max_profit);
		}
	}
	printf("SolutioneTwo: max profit = %d\n", max_profit);
	return max_profit;
}

/* monotonic stack */
int SolutionThree(vector<int> prices) {
	int max_profit = 0;
	vector<int> istack;
	int size = prices.size();
	prices.push_back(-1);
	for (int i = 0; i < size; ++i) {
		while (!istack.empty() && istack.back() > prices[i]) {
			max_profit = std::max(max_profit, istack.back() - istack.front());
			istack.pop_back();
		}
		istack.push_back(prices[i]);
	}
	printf("SolutionThree: max profit = %d\n", max_profit);
	return max_profit;
}

int Solution(vector<int> &prices) {
	srand(time(nullptr));
	int rand_int = rand() % 3 + 1;
	switch (rand_int) {
		case 1: return SolutionOne(prices); break;
		case 2: return SolutionTwo(prices); break;
		case 3: return SolutionThree(prices); break;
	}
	return -1;
}

void Test00121() {
	vector<int> prices = {7, 1, 5, 3, 6, 4};
	// prices = {7, 6, 4, 3, 1};
	Solution(prices);
	printf("end of Test00121\n");
}

int main() {
	Test00121();
}
