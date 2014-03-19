#include "BaseClass.h"
#include <iostream>

class Point: public BaseClass {
public:
	int x;
	int y;
	int z;
	Point() : x(0), y(0), z(0) {}
	Point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
	SAVE {
		REG_MEMBER(_int, x);
		REG_MEMBER(_int, y);
	}ENDSAVE;
	friend std::ostream & operator<<(std::ostream & os, Point & p);
};

int main() {
	using namespace std;
	Point p(3, 4, 5);
	cout << "Current data:\n" << p;
	p.Save(cout);		// serialization - output to std::cout
	cout << "Loading...\n";
	p.Load(cin);		// deserialization - input from std::cin
	p.Save(cout);		// serialization one more time to see how data-members are changed 
	cout << p;
}

std::ostream & operator<<(std::ostream & os, Point & p) {
	os << "x = " << p.x << std::endl
	   << "y = " << p.y << std::endl
	   << "z = " << p.z << std::endl;
	return os;
}