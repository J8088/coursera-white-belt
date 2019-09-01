#include <vector>
#include <string>

using namespace std;

bool IsPalindrom(string x) {
	int n = x.size();
	for (int i = 0; i < n / 2; i++) {
		if (x[i] != x[n - i - 1]) {
			return false;
		}
	}

	return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> res;
	for (auto w : words) {
		if (w.size() >= minLength && IsPalindrom(w)) {
			res.push_back(w);
		}
	}

	return res;
}
