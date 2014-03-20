#include "archive.h"

outArchive::~outArchive() {
	output << "Saved data:\n";
	for (std::vector<int>::iterator i = intArray.begin(); i != intArray.end(); ++i)
		output << "int: " << *i << std::endl;
	output << "End data.\n";
}

inArchive::inArchive(std::istream & is) : input(is) {
	int temp;
	while (!(input >> temp)) {
		input.clear();
		while (input.get() != '\n')
			continue;
	}
	intArray.push_back(temp);
	while (!(input >> temp)) {
		input.clear();
		while (input.get() != '\n')
			continue;
	}
	intArray.push_back(temp);
}