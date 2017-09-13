#ifndef TYPEINFO_H_
#define TYPEINFO_H_

#include "HashMap.h"

class itType;

#define GET_PROPERTY(type,name) &type::get##name
#define SET_PROPERTY(type,name) &type::set##name

#define TYPE_INFO(classname)								\
public:														\
	static itType	type;									\
	virtual itType* getType() const;						\

#define TYPE_INFO_DECL(classname, superClassname)			\
	itType classname::type(#classname, #superClassname);	\
	itType* classname::getType() const {					\
		return &(classname::type);							\
	}

#define DECL_GETTER(classname, methodname)					\
	
// TODO register getter

class itType {
public:
	const char* classname;
	const char* superClassName;

	itType(const char *_classname, const char* _superClassname)
		: classname(_classname)
		, superClassName(_superClassname) {

	}
};
#endif // !TYPEINFO_H_
