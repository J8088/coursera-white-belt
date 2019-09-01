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
#include <regex>

using namespace std;

typedef int64_t I64;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pi;

#define fr(i,a,b) for (int i = a; i <= b; i++)
#define fr2(i,a,b) for (int i = a; i < b; i++)

class Date {
public:
	Date(string date) {
		stringstream ss(date);
		char hyp1, hyp2;
		ss >> year >> hyp1 >> month >> hyp2 >> day;

		if (!ss || ss.peek() != EOF) {
			stringstream serr;
			serr << "Wrong date format: " << date;
			throw logic_error(serr.str());
		}

		if ((month < 1) || (month > 12)) {
			stringstream serr;
			serr << "Month value is invalid: " << month;
			throw logic_error(serr.str());
		}

		if ((day < 1) || (day > 31)) {
			stringstream serr;
			serr << "Day value is invalid: " << day;
			throw logic_error(serr.str());
		}
	}
	Date(int new_year, int new_month, int new_day) {
		year = new_year;
		month = new_month;
		day = new_day;
	}
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			return lhs.GetDay() < rhs.GetDay();
		}

		return lhs.GetMonth() < rhs.GetMonth();
	}

	return lhs.GetYear() < rhs.GetYear();
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear() << "-"
		<< setw(2) << setfill('0') << date.GetMonth() << "-"
		<< setw(2) << setfill('0') << date.GetDay();
	return stream;
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		events[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event) {
		if (events.count(date) && events[date].count(event)) {
			events[date].erase(event);
			return true;
		}

		return false;
	}
	int DeleteDate(const Date& date) {
		int n = 0;
		if (events.count(date)) {
			n = events[date].size();
			events.erase(date);
		}

		return n;
	}
	set<string> Find(const Date& date) const {
		if (events.count(date)) {
			return events.at(date);
		}

		return {};
	}
	void Print() {
		for (const auto& item : events) {
			for (const string& event : item.second) {
				cout << item.first << " " << event << endl;
			}
		}
	}
private:
	map<Date, set<string>> events;
};

int main() {
	Database db;

	string line;
	while (getline(cin, line)) {
		try {
			if (line.empty()) {
				continue;
			}

			stringstream ss(line);
			string cmd;
			ss >> cmd;
			if (cmd == "Add") {
				string date, event;
				ss >> date >> event;

				db.AddEvent(date, event);
			}
			else if (cmd == "Del") {
				string date, event;
				ss >> date >> event;

				if (!event.empty()) {
					if (db.DeleteEvent(date, event)) {
						cout << "Deleted successfully" << endl;
					} else {
						cout << "Event not found" << endl;
					}
				} else {
					int n = db.DeleteDate(date);
					cout << "Deleted " << n << " events" << endl;
				}
			}
			else if (cmd == "Find") {
				string date;
				ss >> date;

				set<string> found_events = db.Find(date);
				for (const string& event : found_events) {
					cout << event << endl;
				}
			}
			else if (cmd == "Print") {
				db.Print();
			}
			else {
				throw invalid_argument("Unknown command: " + cmd);
			}
		} catch (const exception& ex) {
			cout << ex.what() << endl;
		}
	}

	return 0;
}
