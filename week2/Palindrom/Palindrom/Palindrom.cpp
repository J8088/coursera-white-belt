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
