#ifndef ARRAY_H_
#define ARRAY_H_

#include "FacesException.h"
#include <string.h>

template<class T, unsigned int S = 5>
class Array
{
public:
	Array();
	Array(unsigned int _size );

	~Array();

	void				set( const T _item, unsigned int _index );
	int					add( const T _item );
	T					pop();
	T					get( unsigned int _index );

	unsigned int		size() { return m_size; }
	unsigned int		maxSize() { return m_maxSize; }

	const T*			ptr() const { return m_data; }
private:
	unsigned int		m_size;
	unsigned int		m_maxSize;
	T*					m_data;
};

template<class T, unsigned int S>
Array<T,S>::Array() : m_size(0), m_data(0), m_maxSize( S )
{
	m_data = new T[m_maxSize];//( T* ) calloc( m_maxSize, sizeof( T ) );
	memset(m_data, 0, sizeof(T)*m_maxSize);
}

template<class T, unsigned int S>
Array<T,S>::Array(unsigned int _size ) : m_size( _size ), m_maxSize( S )
{
	m_data = new T[_size];//( T* ) calloc( _size, sizeof( T ) );
	memset(m_data, 0, sizeof(T)*_size);
}

template<class T, unsigned int S>
Array<T,S>::~Array()
{
	if( m_data != NULL )
	{
		delete [] m_data;
		m_data = 0;
	}
}

template<class T, unsigned int S>
int Array<T,S>::add( const T _item )
{
	if( m_size >= m_maxSize )
	{
		T *newData = new T[m_size + m_maxSize];
		//m_data = ( T* ) realloc( m_data, sizeof( T) * ( m_size + m_maxSize ) ); // Not Use realloc, malloc or calloc with C++
		m_maxSize += S;
		if (m_size > 0)
		{
			for (unsigned int i = 0; i < m_size; i++)
			{
				newData[i] = m_data[i];
			}
			delete m_data;
			m_data = newData;
		}
	}
	m_data[ m_size ] = _item;
	return m_size++;
}

template<class T, unsigned int S>
void Array<T,S>::set( const T _item, unsigned int _index )
{
	if( _index > m_size )
	{
		throw FacesException( "Out of range!" );
	}

	m_data[ _index ] = _item;
}

template<class T, unsigned int S>
T Array<T,S>::pop()
{
	return 0;
}

template<class T, unsigned int S>
T Array<T,S>::get( unsigned int _index )
{
	if( _index > m_size )
	{
		throw FacesException( "Out of range!" );
	}

	return ( T ) m_data[ _index ];
}

#endif; // ARRAY_H_