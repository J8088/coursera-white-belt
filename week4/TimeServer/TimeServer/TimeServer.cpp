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

string AskTimeServer();

class TimeServer {
public:
	string GetCurrentTime() {
		try {
			LastFetchedTime = AskTimeServer();
		} catch (const system_error& ex) {
		}

		return LastFetchedTime;
	}
private:
	string LastFetchedTime = "00:00:00";
};

int main() {
	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	} catch (exception& e) {
		cout << "Exception got: " << e.what() << endl;
	}
	return 0;
}
