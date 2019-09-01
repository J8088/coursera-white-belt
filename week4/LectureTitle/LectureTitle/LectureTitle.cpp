#include <string>

using namespace std;

struct Specialization {
	explicit Specialization(const string& new_value) {
		value = new_value;
	}
	string value;
};

struct Course {
	explicit Course(const string& new_value) {
		value = new_value;
	}
	string value;
};

struct Week {
	explicit Week(const string& new_value) {
		value = new_value;
	}
	string value;
};

struct LectureTitle {
	string specialization;
	string course;
	string week;

	LectureTitle(const Specialization& s, const Course& c, const Week& w) {
		specialization = s.value;
		course = c.value;
		week = w.value;
	}
};

int main() {
	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);
}
