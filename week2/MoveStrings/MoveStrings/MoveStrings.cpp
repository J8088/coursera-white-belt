#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& a, vector<string>& b) {
	for (auto w : a) {
		b.push_back(w);
	}

	a.clear();
}
