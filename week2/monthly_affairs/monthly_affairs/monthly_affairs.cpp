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

	vi months_days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int current_month = 0;
	vector<vector<string>> affairs(months_days[current_month]);

	int q;
	cin >> q;
	fr2(i, 0, q) {
		string cmd;
		cin >> cmd;
		if (cmd == "DUMP") {
			int j;
			cin >> j;
			j--;

			cout << affairs[j].size() << " ";
			for (auto w : affairs[j]) cout << w << " ";
			cout << endl;
		} else if (cmd == "ADD") {
			int j; string s;
			cin >> j >> s;
			j--;

			affairs[j].push_back(s);
		} else {
			current_month = (current_month + 1) % 12;
			int new_size = months_days[current_month];
			if (new_size < affairs.size()) {
				fr2(h, new_size, affairs.size()) {
					affairs[new_size - 1].insert(end(affairs[new_size - 1]), begin(affairs[h]), end(affairs[h]));
				}
			}
			affairs.resize(new_size);
		}
	}

	return 0;
}
