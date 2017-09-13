#ifndef ILAYOUT_H_
#define ILAYOUT_H_

//#include "faces.h"

class Container;

class ILayout
{
public:
	virtual void doLayout( Container& _container ) = 0;

	float		getGap() { return m_gap; }
	void		setGap(float _value) { m_gap = _value; }

	float		getPaddingLeft() { return m_paddingLeft; }
	void		setPaddingLeft(float _value) { m_paddingLeft = _value; }

	float		getPaddingTop() { return m_paddingTop; }
	void		setPaddingTop(float _value) { m_paddingTop = _value; }

protected:
	void		init(float _paddingLeft, float _paddingTop, float _gap);

	float		m_gap;
	float		m_paddingLeft;
	float		m_paddingTop;
};

#endif; // !ILAYOUT_H_
