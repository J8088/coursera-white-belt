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
	int a = lhs.Numerator();
	int b = lhs.Denominator();
	int c = rhs.Numerator();
	int d = rhs.Denominator();
	return { a * d, b * c };
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
	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}

	cout << "OK" << endl;

	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal) {
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal) {
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}

	cout << "OK" << endl;

	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 4;
		}
	}

	cout << "OK" << endl;

	{
		const set<Rational> rs = { { 1, 2 },{ 1, 25 },{ 3, 4 },{ 3, 4 },{ 1, 2 } };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;

	return 0;
}
