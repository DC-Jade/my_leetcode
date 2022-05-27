#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

vector<int> RelativeSortArray(vector<int> &arr1, vector<int> &arr2);

vector<int> SolutionOne(vector<int> &arr1, const vector<int> &arr2) {
	unordered_map<int, int> rank;
	for (int i = 0; i < arr2.size(); ++i) { rank[arr2[i]] = i; }
	std::sort(arr1.begin(), arr1.end(), [&](int x, int y) {
		if (rank.count(x)) { return rank.count(y) ? rank[x] < rank[y] : true; }
		else { return rank.count(y) ? false : x < y; }
	});
	return arr1;
}

// bool Compare(int x, int y, unordered_map<int, int> &rank) {
//   if (rank.count(x)) { return rank.count(y) ? rank[x] < rank[y] : true; }
//   else { return rank.count(y) ? false : x < y; }
// }
// bool Compare(int x, int y) {
//   return x > y;
// }

/* replace lamda with function pointer  */
// vector<int> SolutionTwo(vector<int> &arr1, const vector<int> &arr2) {
//   unordered_map<int, int> rank;
//   for (int i = 0; i < arr2.size(); ++i) { rank[arr2[i]] = i; }
//   std::sort(arr1.begin(), arr1.end(), Compare(x, y, rank));
//   return arr1;
// }

vector<int> Solution(vector<int> &arr1, const vector<int> &arr2) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(arr1, arr2); break;
		// case 2: printf("SolutionTwo\n"); return SolutionTwo(arr1, arr2); break;
	}
	return {0};
}

void Test01122() {
	vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
	vector<int> arr2 = {2,1,4,3,9,6};
	Solution(arr1, arr2);
	for (auto &i : arr1) printf("%d ", i);
	printf("\n");
}

int main(int argc, char **argv) {
	Test01122();
}
