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
};

int main() {
	using namespace std;
	Point p(3, 4, 5);
	cout << "Current data:\n";
	cout << "x = " << p.x << std::endl
	     << "y = " << p.y << std::endl
	     << "z = " << p.z << std::endl;
	p.Save(std::cout);
	cout << "Loading...\n";
	p.Load(std::cin);
	p.Save(std::cout);
	std::cout << "x = " << p.x << std::endl;
	std::cout << "y = " << p.y << std::endl;
	std::cout << "z = " << p.z << std::endl;
}