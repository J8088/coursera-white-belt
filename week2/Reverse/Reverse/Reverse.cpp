#include <vector>

using namespace std;

void Reverse(vector<int>& numbers) {
	int n = numbers.size();
	for (int i = 0; i < n / 2; i++) {
		int tmp = numbers[i];
		numbers[i] = numbers[n - i - 1];
		numbers[n - i - 1] = tmp;
	}
}
