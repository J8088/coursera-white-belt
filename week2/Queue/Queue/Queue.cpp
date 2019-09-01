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

	vb a;
	int q;
	cin >> q;

	fr2(i, 0, q) {
		string cmd;
		cin >> cmd;
		if (cmd == "WORRY_COUNT") {
			int count = 0;
			for (auto c : a) {
				if (c) count++;
			}
			cout << count << "\n";
		} else {
			int k;
			cin >> k;

			if (cmd == "WORRY") a[k] = true;
			else if (cmd == "QUIET") a[k] = false;
			else {
				if (k > 0) {
					a.insert(end(a), k, false);
				} else {
					a.erase(end(a) + k, end(a));
				}
			}
		}
	}

	return 0;
}
