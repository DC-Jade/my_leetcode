#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <unordered_map>

using std::unordered_map;
using std::string;

int RomanToInt(string s);

int SolutionOne(const string &s) {
	// unordered_map<char, int> hashtable;
	// hashtable.insert({{'I', 1}, {'V', 5},
	//     {'X', 10}, {'L', 50},
	//     {'C', 100}, {'D', 500},
	//     {'M', 1000}});
	unordered_map<char, int> hashtable = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000},
	};
	int size = s.size();
	int i = 0; int j = 1;
	int sum = 0;
	int cur_val = hashtable[s[i]];
	int next_val = 0;
	/* case size == 1 */
	if (size < 2) return cur_val;
	while (j < size) {
		cur_val = hashtable[s[i]];
		next_val = hashtable[s[j]];
		if (cur_val == 1 && (next_val == 5 || next_val == 10))
			sum -= cur_val;
		else if (cur_val == 10 && (next_val == 50 || next_val == 100))
			sum -= cur_val;
		else if (cur_val == 100 && (next_val == 500 || next_val == 1000))
			sum -= cur_val;
		else
			sum += cur_val;
		/* switch is wrong, swtich used in one condition, but there are more than */
		/* one condition */
		// switch (cur_val) {
		//   case 1:
		//     if (next_val == 5 || next_val == 10)
		//       sum -= cur_val;
		//     break;
		//   case 10:
		//     if (cur_val == 10 && (next_val == 50 || next_val == 100))
		//       sum -= cur_val;
		//     break;
		//   case 100:
		//     if (cur_val == 100 && (next_val == 500 || next_val == 1000))
		//       sum -= cur_val;
		//     break;
		//   default:
		//     sum += cur_val;
		//     break;
		// }
		++i; ++j;
	}
	sum += next_val;
	return sum;
}

int Solution(const string &s) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 1;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(s);
	}
	return -1;
}

void Test00013() {
	string s = "III";
	s = "LVIII";
	s = "MCMXCIV";
	int res = 0;
	res = Solution(s);
	printf("%d\n", res);
	printf("end of Test00013\n");
}

int main(int argc, char **argv) {
	Test00013();
}

