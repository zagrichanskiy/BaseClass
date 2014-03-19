#ifndef BASE_CLASS_H_
#define BASE_CLASS_H_

#include <vector>
#include <iostream>

#define SAVE void serialize(Archive & ar)
#define REG_MEMBER(_type, member) ar & member;
#define ENDSAVE 

class Archive {
public:
	std::vector<int> intArray;
	virtual void operator&(int &) = 0;
	virtual ~Archive() {}
};

class outArchive: public Archive {
public:
	void outArchive::operator&(int & value) {
		intArray.push_back(value);
	}
};

class inArchive: public Archive {
public:
	void inArchive::operator&(int & value) {
		value = *intArray.begin();
		intArray.erase(intArray.begin());
	}
};

class BaseClass {
public:
	void Load(std::istream & is);
	void Save(std::ostream & os);
	virtual void serialize(Archive & ar) = 0;
	virtual ~BaseClass() {}
};

#endif