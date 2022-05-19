#include <stdio.h>

#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>

using std::string;
using std::vector;

int LongestPalindrome(const string &s);

int SolutionOne(const string &s) {
	vector<int> iv(52, 0);
	int size = s.size();
	int index = 0;
	int res_count = 0;

	/* case length == 1 */
	if (size == 1) {
		res_count = 1;
		printf("SolutionOne: %d\n", res_count);
		return res_count;
	}
	/* case length > 1 */
	for (int i = 0; i < size; ++i) {
		if (!islower(s[i])) index = s[i] - 'A';
		else index = s[i] - 'a' + 25 + 1;
		++iv[index];
		if (iv[index] > 0 && iv[index] % 2 == 0) ++res_count;

		/* case "ccccc" */
		if (iv[index] == size) {
			res_count = size;
			printf("SolutionOne: %d\n", res_count);
			return size;
		}
		
	}
	/* odd 2 * count + 1; even && size == 2 * count : 2 * count */
	res_count =  (size % 2 == 0 && (size >> 1) == res_count) ? res_count * 2 : res_count * 2 + 1;
	printf("SolutionOne: %d\n", res_count);
	return res_count;
}

int SolutionTwo(const string &s) {
	vector<int> iv(128, 0);
	int size = s.size();
	int count = 0; 
	for (auto c : s) {
		/* int & 1 check odd int & 0 even */
		if (iv[c] & 1) count += 2;
		++iv[c];
	}
	if (size > count) ++count;
	printf("SolutionTwo: %d\n", count);
	return count;
}

int Solution(const string &s) {
	srand(time(nullptr));
	int rand_int = rand() % 2 + 1;
	switch (rand_int) {
		case 1: return SolutionOne(s); break;
		case 2: return SolutionTwo(s); break;
	}
	return -1;
}

void Test00409() {
	string s = "abccccdd";
	s = "a";
	s = "bb";
	s = "bbb";
	s = "abb";
	Solution(s);
}

int main() {
	Test00409();
}
