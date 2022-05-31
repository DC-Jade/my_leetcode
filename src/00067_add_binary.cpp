#include <cstdlib>
#include <cstdio>
#include <algorithm>

#include <string>

using std::string;

string AddBinary(string &a, string &b);
string SolutionOne(string &a, string &b);
string Solution(string &a, string &b);

string SolutionOne(string &a, string &b) {
	/* b shorter than a */
	if (a.size() < b.size()) return SolutionOne(b, a);

	string s = "";
	int a_size = a.size(), b_size = b.size();
	int cur_val = 0;
	int i = a_size - 1, j = b_size - 1;
	for (; j >= 0; --i, --j) {
		cur_val += a[i] + b[j] - '0' - '0';
		if (cur_val < 2) {
			s.push_back(cur_val + '0');
			cur_val = 0;
		} else  {
			s.push_back(cur_val % 2 + '0');
			cur_val = 1;
		}
	}
	/* b use up */
	for (; i >= 0; --i) {
		cur_val += a[i] - '0';
		if (cur_val < 2) {
			s.push_back(cur_val + '0');
			cur_val = 0;
		} else {
			s.push_back(cur_val % 2 + '0');
			cur_val = 1;
		}
	} 
	if (cur_val == 1) s.push_back(cur_val + '0');
	std::reverse(s.begin(), s.end());
	return s;
}

/* bit operation */
// string SolutionTwo(string &a, string &b) {
//   if (a.size() < b.size()) return SolutionTwo(b, a);
//
//   int i = a.size(), k = b.size();
//   string res = "";
//   int carry = 0;
//   for (; k >= 0; --i, --k) {
//     res.push_back((a[i] - '0') ^ (b[k] - '0') ^ carry);
//     carry = (a[i] & b[k]) << 1;
//   }
//   for (; i >= 0; --i) {
//     res.push_back((a[i] - '0') ^ carry);
//     carry = ((a[i] - '0') ^ carry);
//   }
//   if (carry == 1) res.push_back(carry);
//   std::sort(res.being(), res.end());
//   return res;
// }
//

string SolutionThree(string &a, string &b) {
	string res = "";
	int carry = 0;
	int i = a.size() - 1, k = b.size() - 1;
	while (i >= 0 || k >= 0) {
		if (i >= 0) carry += a[i--] - '0';
		if (k >= 0) carry += b[k--] - '0';
		res.push_back(carry % 2 + '0');
		carry /= 2;
	}
	if (carry == 1) res.push_back(carry + '0');
	std::reverse(res.begin(), res.end());
	return res;
}

string Solution(string &a, string &b) {
	srand(time(nullptr));
	int rand_int = rand() % 1 + 3;
	switch (rand_int) {
		case 1: printf("SolutionOne\n"); return SolutionOne(a, b); break;
		case 3: printf("SolutionThree\n"); return SolutionThree(a, b); break;
	}
	return "";
}

void Test00067() {
	string a = "11";
	string b = "1";
	a = "1010";
	b = "1011";
	string res = Solution(a, b);
	printf("%s\n", res.c_str());
}

int main(int argc, char **argv) {
	Test00067();
}
