#include "itString.h"

itString::itString()
	: m_value(NULL)
	, m_size(0)
{
}

itString::itString(const itString& _value)
{
	m_size = _value.size();
	m_value = new char[m_size+1];
	strcpy(m_value, _value.m_value);
}

itString::itString(const char* _str)
{
	m_size = strlen(_str);
	m_value = new char[m_size+1];
	strcpy(m_value, _str);
}


itString::~itString()
{
	//if( m_value != NULL)
	//	delete[] m_value;
}

inline int itString::size() const
{
	return m_size;
}

bool itString::operator==(const itString& _str)
{
	return strcmp(m_value, _str.m_value) == 0;
}

void itString::operator=(const char *_value) {
	char *newValue;
	int size, i;

	if (_value == NULL) {
		return;
	}

	if (_value == m_value) return;

	size = strlen(_value);
	newValue = new char[size];
	strcpy(newValue, _value);

	if (m_value)
		delete[] m_value;

	m_size = size;
	m_value = newValue;
}
