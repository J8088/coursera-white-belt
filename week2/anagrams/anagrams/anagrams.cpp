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

map<char, int> BuildCharCounters(string word) {
	map<char, int> counts;
	for (auto c : word) {
		counts[c]++;
	}

	return counts;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	fr2(i, 0, n) {
		string sa, sb;
		cin >> sa >> sb;

		if (BuildCharCounters(sa) == BuildCharCounters(sb)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
