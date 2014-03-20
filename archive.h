#ifndef ARCHIVE_H_
#define ARCHIVE_H_

#include <iostream>
#include <vector>

class Archive {
public:
	std::vector<int> intArray;
	virtual void operator&(int &) = 0;
	virtual ~Archive() {}
};

class outArchive : public Archive {
private:
	std::ostream & output;
public:
	outArchive(std::ostream & os) : output(os) {}
	~outArchive();
	void outArchive::operator&(int & value) {
		intArray.push_back(value);
	}
};

class inArchive : public Archive {
private:
	std::istream & input;
public:
	inArchive(std::istream & is);
	void inArchive::operator&(int & value) {
		value = *intArray.begin();
		intArray.erase(intArray.begin());
	}
};

#endif