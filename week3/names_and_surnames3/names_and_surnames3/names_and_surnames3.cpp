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
		}
		else {
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
		}
		else {
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
	Person(string name, string surname, int year) {
		names[year] = name;
		surnames[year] = surname;
		birth_year = year;
	}
	void ChangeFirstName(int year, const string& first_name) {
		if (year < birth_year) {
			return;
		}

		names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		if (year < birth_year) {
			return;
		}

		surnames[year] = last_name;
	}
	string GetFullName(int year) const {
		if (year < birth_year) {
			return "No person";
		}

		const string name = FindNameByYear(names, year);
		const string surname = FindNameByYear(surnames, year);

		return GetFormattedFullName(name, surname);
	}
	string GetFullNameWithHistory(int year) const {
		if (year < birth_year) {
			return "No person";
		}

		const string name = FindAllNamesByYear(names, year);
		const string surname = FindAllNamesByYear(surnames, year);

		return GetFormattedFullName(name, surname);
	}
private:
	int birth_year;
	map<int, string> names;
	map<int, string> surnames;

	string GetFormattedFullName(string name, string surname) const {
		if (name.empty() && surname.empty()) {
			return "Incognito";
		}
		else if (name.empty()) {
			return surname + " with unknown first name";
		}
		else if (surname.empty()) {
			return name + " with unknown last name";
		}
		else {
			return name + " " + surname;
		}
	}
};

int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}
