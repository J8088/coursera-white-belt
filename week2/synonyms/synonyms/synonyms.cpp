#include <algorithm>
#include <functional>
#include <cmath>
#include <limits>
#include <cfloat>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef int64_t I64;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pi;

#define fr(i,a,b) for (int i = a; i <= b; i++)
#define fr2(i,a,b) for (int i = a; i < b; i++)

int main() {
	ios_base::sync_with_stdio(false);

	int q;
	cin >> q;

	map<string, set<string>> synonyms;

	fr2(i, 0, q) {
		string cmd;
		cin >> cmd;

		if (cmd == "ADD") {
			string word1, word2;
			cin >> word1 >> word2;

			synonyms[word1].insert(word2);
			synonyms[word2].insert(word1);
		} else if (cmd == "COUNT") {
			string word;
			cin >> word;

			cout << synonyms[word].size() << endl;
		} else {
			string word1, word2;
			cin >> word1 >> word2;

			if (synonyms[word1].count(word2) || synonyms[word2].count(word1)) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}

	return 0;
}
