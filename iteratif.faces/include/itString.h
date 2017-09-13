#ifndef ITSTRING_H_
#define ITSTRING_H_

//#include "faces.h"
#include <stdlib.h>
#include <tchar.h>

class itString
{
public:
	itString();
	itString(const itString& _value);
	itString(const char *_str);
	~itString();

	int				size() const;
	void			append(const itString& _value);
	void			append(const itString& _value, int _index);
	int				indexOf(char _value);
	int				indexLastOf(char _value);
	itString		substr(int _index);
	itString		substr(int _start, int _end);
	const char*		c_str() const;
	static int		Hash(const char *_key);

	bool			operator==(const itString& _str);
	void			operator=(const char *_value);
	char			operator[](int _index) const;
	operator		const char*();
	operator		const char*() const;

protected:
	char			*m_value;
	int				m_size;
};

inline char itString::operator[](int _index) const {
	return m_value[_index];
}

inline itString operator+( const itString &a, const itString &b) {
	itString value(a);
	value.append(b);
	return value;
}

inline int itString::indexOf(char _value) {
	int i;
	int index = -1;
	for (i = 0; i < m_size; i++) {
		if (m_value[i] == _value) return i;
	}
	return index;
}

inline int itString::indexLastOf(char _value) {
	int i;
	int index = -1;
	for (i = m_size - 1; i > -1; i--) {
		if (m_value[i] == _value) return i;
	}
	return index;
}

inline int itString::Hash(const char *_key) {
	int hash = 0;
	const char *str = _key;
	// Comprendre pas pourquoi (i + 119) : c'est un offset ok mais sur quoi il se base ????
	for (int i = 0; *str != '\0'; i++) {
		hash += (*str++) * (i + 119);
	}
	return hash;
}

inline void itString::append(const itString& _value)
{
	int newSize, i;
	char *newValue;
	int size;

	size = _value.size();
	newSize = m_size + size;
	if (newSize == m_size) {
		return;
	}

	newValue = new char[newSize];
	strcpy(newValue, m_value);
	for (i = 0; i < size; i++) {
		newValue[i + m_size] = _value[i];
	}
	newValue[newSize] = '\0';

	m_size = newSize;
	m_value = newValue;
}

inline void itString::append(const itString& _value, int _index)
{
	// @TODO test _index
	int newSize;
	char *newValue;
	int size;

	size = _value.size();
	newSize = size - _index;
	if (newSize < 0) {
		return;
	}

	newValue = new char[newSize];
	strcpy(newValue, &_value.m_value[_index]);

	m_size = newSize;
	m_value = newValue;
}

inline itString itString::substr(int _index) {
	itString value;
	value.append(*this, _index);
	return value;
}

inline itString itString::substr(int _start, int _end) {
	int i, size;
	
	char *newValue;
	size = _end - _start;
	newValue = new char[size];
	for (i = 0; i < size; i++) {
		newValue[i] = m_value[i+_start];
	}
	newValue[size] = '\0';
	itString value(newValue);
	return value;
}

inline const char*itString::c_str() const {
	return m_value;
}

inline itString::operator const char *() {
	return c_str();
}

inline itString::operator const char *() const {
	return c_str();
}

#endif // !ITSTRING_H_

