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

string FindNameByYear(const map<int, string>& names, int year) {
	string name;
	for (const auto& item : names) {
		if (item.first <= year) {
			name = item.second;
		} else {
			break;
		}
	}

	return name;
}

string FindAllNamesByYear(const map<int, string>& names, int year) {
	vector<string> latest_names;
	for (const auto& item : names) {
		if (item.first <= year) {
			if (latest_names.empty() || (latest_names.back() != item.second)) {
				latest_names.push_back(item.second);
			}
		} else {
			break;
		}
	}

	int n = latest_names.size();
	string res_name = (n > 0) ? latest_names[n - 1] : "";
	if (n > 1) {
		res_name += " (";
		for (int i = n - 2; i >= 0; i--) {
			res_name += latest_names[i];
			if (i > 0) res_name += ", ";
		}
		res_name += ")";
	}

	return res_name;
}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		surnames[year] = last_name;
	}
	string GetFullName(int year) {
		const string name = FindNameByYear(names, year);
		const string surname = FindNameByYear(surnames, year);

		return GetFormattedFullName(name, surname);
	}
	string GetFullNameWithHistory(int year) {
		const string name = FindAllNamesByYear(names, year);
		const string surname = FindAllNamesByYear(surnames, year);

		return GetFormattedFullName(name, surname);
	}
private:
	map<int, string> names;
	map<int, string> surnames;

	string GetFormattedFullName(string name, string surname) {
		if (name.empty() && surname.empty()) {
			return "Incognito";
		} else if (name.empty()) {
			return surname + " with unknown first name";
		} else if (surname.empty()) {
			return name + " with unknown last name";
		}  else {
			return name + " " + surname;
		}
	}
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}
