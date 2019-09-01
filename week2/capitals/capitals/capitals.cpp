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

	map<string, string> capitals;

	fr2(i, 0, q) {
		string cmd;
		cin >> cmd;

		if (cmd == "CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;

			if (!capitals.count(country)) {
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
			} else if (capitals[country] == new_capital) {
				cout << "Country " << country << " hasn't changed its capital" << endl;
			} else {
				cout << "Country " << country << " has changed its capital from " << capitals[country]
					<< " to " << new_capital << endl;
			}

			capitals[country] = new_capital;
		} else if (cmd == "RENAME") {
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;

			if ((old_country_name == new_country_name)
				|| capitals.count(new_country_name)
				|| !capitals.count(old_country_name)) {
				cout << "Incorrect rename, skip" << endl;
			} else {
				cout << "Country " << old_country_name << " with capital " << capitals[old_country_name]
					<< " has been renamed to " << new_country_name << endl;
				capitals[new_country_name] = capitals[old_country_name];
				capitals.erase(old_country_name);
			}
		} else if (cmd == "ABOUT") {
			string country;
			cin >> country;

			if (!capitals.count(country)) {
				cout << "Country " << country << " doesn't exist" << endl;
			} else {
				cout << "Country " << country << " has capital " << capitals[country] << endl;
			}
		} else {
			if (!capitals.size()) {
				cout << "There are no countries in the world" << endl;
			} else {
				for (const auto& item : capitals) {
					cout << item.first << "/" << item.second << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}
