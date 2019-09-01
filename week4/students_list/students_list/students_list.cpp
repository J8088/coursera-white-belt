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

struct Student {
	string name;
	string surname;
	int day;
	int month;
	int year;
};

int main() {
	int n;
	cin >> n;

	vector<Student> students;

	fr2(i, 0, n) {
		string name;
		string surname;
		int day;
		int month;
		int year;
		cin >> name >> surname >> day >> month >> year;

		students.push_back({ name,surname, day,month,year });
	}

	int m;
	cin >> m;

	fr2(i, 0, m) {
		string cmd;
		int k;
		cin >> cmd >> k;
		k--;

		if (cmd == "name" && (k >= 0) && (k <= n - 1)) {
			cout << students[k].name << " " << students[k].surname << endl;
		}
		else if (cmd == "date" && (k >= 0) && (k <= n - 1)) {
			cout << students[k].day << "." << students[k].month << "." << students[k].year << endl;
		}
		else {
			cout << "bad request" << endl;
		}
	}

	return 0;
}
