#ifndef CLASSFACTORY_H_
#define CLASSFACTORY_H_

#include "HashMap.h"

#define REGISTER_VIEW(n) factory.Register<n>(#n);
#define INSTANCE_VIEW(n) factory.CreateInstance(n)

template<class T> void* constructor() { return (void*) new T(); }

class ClassFactory {
public:
	template<class T>
	void Register(const char *_classname) {
		m_classes.Set(_classname, &constructor<T>);
	}

	void* CreateInstance(const char *_classname) {
		constructor_t func = m_classes.Get(_classname);
		return func();
	}

private:
	typedef void*(*constructor_t)();
	typedef iteratif::HashMap<constructor_t> map_type;
	map_type m_classes;
};

extern ClassFactory factory;

#endif // !CLASSFACTORY_H_


