#ifndef FACESEXCEPTION_H_
#define FACESEXCEPTION_H_

class FacesException {
public:
	FacesException( const char *_message ) throw() {
		m_message = _message;
	}

	const char * getMessage() const throw()
	{
		return m_message;
	}

private:
	const char * m_message;
};

#endif; // FACESEXCEPTION_H_