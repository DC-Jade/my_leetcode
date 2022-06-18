#include <cstdio>
#include <algorithm>
#include <string>

using std::string;

string AddString(string num1, string num2);
string SolutionOne(const string &num1, const string &num2);
string SolutionTwo(const string &num1, const string &num2);
string Solution(const string &num1, const string &num2);

int Product(int base, int n) {
	int res = 1;
	while (n--) {
		res *= base;
	}
	return res;
}

int Str2Int(const string &str) {
	int len = str.size();
	int res = 0;
	int base = 10;
	for (int i = 0; i < len; ++i) {
		res += (str[len - i - 1] - '0') * Product(base, i);
	}
	return res;
}

string Int2Str(const int &n) {
  int residual = n;
  string res = "";
  do {
    res.push_back(residual % 10 + '0');
  } while (residual /= 10);
  reverse(res.begin(), res.end());
  return res;
}

/* int overflow */
string SolutionOne(const string &num1, const string &num2) {
	int i = Str2Int(num1);
	int j = Str2Int(num2);
	int sum = i + j;
	string res = Int2Str(sum);
	return res;
}

/* simulation */
string SolutionTwo(const string &num1, const string &num2) {
	int i = num1.size() - 1, j = num2.size() - 1;
	int add = 0;
	string res = "";
	while (i >= 0 || j >= 0) {
		if (i >=0 && j >= 0) {
			res.push_back(((num1[i] - '0') + (num2[j] - '0') + add) % 10 + '0');
			add = ((num1[i] - '0') + (num2[j] - '0') + add) / 10;
		} else if (i >= 0) {
			res.push_back(((num1[i] - '0') + add) % 10 + '0');
			add = ((num1[i] - '0') + add) / 10;
		} else {
			res.push_back(((num2[j] - '0') + add) % 10 + '0');
			add = ((num2[j] - '0') + add) / 10;
		}
		--i; --j;
	}
	if (add) { res.push_back(add + '0'); }
	reverse(res.begin(), res.end());
	return res;
}

string Solution(const string &num1, const string &num2) {
	switch (rand() % 1 + 1) {
		case 1: printf("SolutionTwo\n"); return SolutionTwo(num1, num2);
		default: printf("SolutionOne\n"); return SolutionOne(num1, num2);
	}
}

void Test00415() {
	string num1 = "0", num2 = "0";
	num1 = "456"; num2 = "77";
	num1 = "1"; num2 = "9";
	string res = Solution(num1, num2);
	printf("%s\n", res.c_str());
}

int main() {
	Test00415();
}
