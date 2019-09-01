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

	map<string, vector<string>> bus_stops;
	map<string, vector<string>> stops_buses;

	fr2(i, 0, q) {
		string cmd;
		cin >> cmd;

		if (cmd == "NEW_BUS") {
			string bus;
			cin >> bus;

			int n;
			cin >> n;

			fr2(j, 0, n) {
				string stop;
				cin >> stop;

				bus_stops[bus].push_back(stop);
				stops_buses[stop].push_back(bus);
			}
		} else if (cmd == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;

			if (!stops_buses.count(stop)) {
				cout << "No stop" << endl;
			} else {
				for (string bus : stops_buses[stop]) {
					cout << bus << " ";
				}
				cout << endl;
			}
		} else if (cmd == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;

			if (!bus_stops.count(bus)) {
				cout << "No bus" << endl;
			} else {
				for (string stop : bus_stops[bus]) {
					cout << "Stop " << stop << ": ";
					if (stops_buses[stop].size() <= 1) {
						cout << "no interchange" << endl;
					} else {
						for (string other_bus : stops_buses[stop]) {
							if (other_bus == bus) continue;
							cout << other_bus << " ";
						}
						cout << endl;
					}
				}
			}
		} else {
			if (!bus_stops.size()) {
				cout << "No buses" << endl;
			}
			for (const auto& item : bus_stops) {
				cout << "Bus " << item.first << ": ";
				for (string stop : item.second) {
					cout << stop << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}
