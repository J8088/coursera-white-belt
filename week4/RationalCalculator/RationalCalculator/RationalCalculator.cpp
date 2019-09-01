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

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}
	Rational(int p, int q) {
		if (q == 0) {
			throw invalid_argument("Invalid argument");
		}

		int d = gcd(p, q);
		p /= d;
		q /= d;

		if (q < 0) {
			p = -p;
			q = -q;
		}

		numerator = p;
		denominator = q;
	}

	int Numerator() const {
		return numerator;
	}
	int Denominator() const {
		return denominator;
	}
private:
	int numerator;
	int denominator;
};

Rational operator+(const Rational& lhs, const Rational& rhs) {
	int a = lhs.Numerator();
	int b = lhs.Denominator();
	int c = rhs.Numerator();
	int d = rhs.Denominator();
	return { a * d + b * c, b * d };
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	int a = lhs.Numerator();
	int b = lhs.Denominator();
	int c = rhs.Numerator();
	int d = rhs.Denominator();
	return { a * d - b * c, b * d };
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	int a = lhs.Numerator();
	int b = lhs.Denominator();
	int c = rhs.Numerator();
	int d = rhs.Denominator();
	return { a * c, b * d };
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	if (rhs.Numerator() == 0) {
		throw domain_error("Division by zero");
	}

	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

bool operator==(const Rational& lhs, const Rational& rhs) {
	int a = lhs.Numerator();
	int b = lhs.Denominator();
	int c = rhs.Numerator();
	int d = rhs.Denominator();
	return (a == c) && (b == d);
}

bool operator<(const Rational& lhs, const Rational& rhs) {
	return (lhs - rhs).Numerator() < 0;
}

istream& operator>>(istream& in, Rational& r) {
	int p, q;
	char div;
	in >> p >> div >> q;

	if (in && div == '/') {
		r = Rational(p, q);
	}

	return in;
}

ostream& operator<<(ostream& out, const Rational& r) {
	out << r.Numerator() << "/" << r.Denominator();
	return out;
}

int main() {
	Rational l, r;
	char op;

	try {
		cin >> l >> op >> r;
		if (op == '+') {
			cout << l + r << endl;
		} else if (op == '-') {
			cout << l - r << endl;
		} else if (op == '*') {
			cout << l * r << endl;
		} else {
			cout << l / r << endl;
		}
	} catch (const exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}
