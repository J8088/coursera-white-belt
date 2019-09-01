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

	double a, b, c;
	cin >> a >> b >> c;

	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				cout << 0;
			} // иначе нет решений
		} else {
			cout << -c / b;
		}
	} else {
		double d = b * b - 4 * a * c;
		if (d == 0) {
			cout << -b / (2.0 * a);
		} else if (d > 0) {
			double x1 = (-b + sqrt(d)) / (2 * a);
			double x2 = (-b - sqrt(d)) / (2 * a);
			cout << x1 << " " << x2;
		} // иначе нет решений
	}

	return 0;
}
