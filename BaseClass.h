#ifndef BASE_CLASS_H_
#define BASE_CLASS_H_

#include "archive.h"

#define SAVE void serialize(Archive & ar)
#define REG_MEMBER(_type, member) ar & member;
#define ENDSAVE 

class BaseClass {
public:
	void Load(std::istream & is) {
		inArchive ar(is);
		serialize(ar);
	}
	void Save(std::ostream & os) {
		outArchive ar(os);
		serialize(ar);
	}
	virtual void serialize(Archive & ar) = 0;
	virtual ~BaseClass() {}
};

#endif