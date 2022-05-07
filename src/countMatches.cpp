
#include <vector>
#include <string>
#include <cstdio>

using std::vector;
using std::string;

// [type, color, name]
void Input(vector<vector<string>> &item) {
	string s;
	int i = 0, j = 0;
	while (scanf("%s", &s) != EOF) { while (j < 3) item[i][j++] = s; 
		++i; j = 0;
	} 
}


int countMatches(vector<vector<string>> &item, string ruleKey,
		string ruleValue) {
	int ans = 0;
	int s = ruleKey == "name" ? 2 : ruleKey == "color";
	for (vector<string> &i : item)
			if(i[s] == ruleValue) ++ans;
	return ans;
}

int main() {
	vector<vector<string>> items = {{"phone","blue","pixel"},
		{"phone","blue","pixel"}};
	Input(items);
}
