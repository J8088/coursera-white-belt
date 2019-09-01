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

string str_to_lower(string s) {
	string ls = s;
	fr2(i, 0, s.size()) ls[i] = tolower(ls[i]);

	return ls;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<string> vs(n);
	for (string& s : vs) cin >> s;

	sort(begin(vs), end(vs), [](string a, string b) { return str_to_lower(a) < str_to_lower(b); });

	for (const string& s : vs) cout << s << " ";

	return 0;
}
