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

	map<vector<string>, int> stops_to_buses;

	int q;
	cin >> q;

	int index = 0;
	fr2(i, 0, q) {
		int n;
		cin >> n;

		vector<string> stops(n);
		for (string& stop : stops) cin >> stop;

		if (stops_to_buses.count(stops)) {
			cout << "Already exists for " << stops_to_buses[stops] << endl;
		} else {
			index++;
			stops_to_buses[stops] = index;
			cout << "New bus " << index << endl;
		}
	}

	return 0;
}
