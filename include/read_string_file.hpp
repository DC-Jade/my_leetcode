#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <assert.h>

using std::vector;
using std::string;

/* read string from file by line */
vector<string> *ReadStringFile(vector<string> *pvec_str);

vector<string> *ReadStringFile(vector<string> *pvec_str) {
	/* this statement cannot initialize, so will throw segmention fault */
	// vector<string> *pvec_str;  

	std::ifstream file("../data/2011_operation.txt");
	string operation;
	while (std::getline(file, operation, '\n')) {
		/* index may adress invalid pointer */
		// (*pvec_str)[i++] = operation;

		assert(pvec_str != nullptr);
		pvec_str->push_back(operation);
	}
	return pvec_str;
}

void PrintVecStr(const vector<string> &vec_str) {
	for (auto op : vec_str)
		/* printf need pointer arg, c_str convert string to char * */
		printf("%s\n", op.c_str());
}

void Test() {
	vector<string> vec_str;
	ReadStringFile(&vec_str);
	PrintVecStr(vec_str);
}


