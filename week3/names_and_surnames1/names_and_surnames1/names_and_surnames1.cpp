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

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		surnames[year] = last_name;
	}
	string GetFullName(int year) {
		string latest_name, latest_surname;
		for (const auto& item : names) {
			if ((item.first <= year) && item.second.size()) {
				latest_name = item.second;
			}
		}

		for (const auto& item : surnames) {
			if ((item.first <= year) && item.second.size()) {
				latest_surname = item.second;
			}
		}

		if (!latest_name.size() && !latest_surname.size()) {
			return "Incognito";
		} else if (!latest_name.size()) {
			return latest_surname + " with unknown first name";
		} else if (!latest_surname.size()) {
			return latest_name + " with unknown last name";
		} else {
			return latest_name + " " + latest_surname;
		}
	}
private:
	map<int, string> names;
	map<int, string> surnames;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}
