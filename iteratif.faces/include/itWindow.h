#ifndef ITWINDOW_H_
#define ITWINDOW_H_

#include <Windows.h>

class itWindow
{
public:
	itWindow( int width, int height );
	~itWindow(void);

	bool Init();
	HWND GetHandle();
protected:
	HWND m_handle;
	int m_ClientWidth;
	int m_ClientHeight;
};

#endif // ITWINDOW_H_
