#include "BaseClass.h"

void BaseClass::Save(std::ostream & os) {
	outArchive ar;
	serialize(ar);
	os << "Saved data:\n";
	for (std::vector<int>::iterator i = ar.intArray.begin(); i != ar.intArray.end(); ++i)
		os << "int: " << *i << std::endl;
	os << "End data.\n";
}

void BaseClass::Load(std::istream & is) {
	inArchive ar;
	int temp;
	while (!(std::cin >> temp)) {
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
	ar.intArray.push_back(temp);
	while (!(std::cin >> temp)) {
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
	ar.intArray.push_back(temp);
	serialize(ar);
}