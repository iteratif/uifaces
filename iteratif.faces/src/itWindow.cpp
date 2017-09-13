#include "itWindow.h"
#include <Windows.h>

LRESULT CALLBACK WinProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	if( msg == WM_DESTROY ||
		msg == WM_CLOSE )
	{
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc( hwnd, msg, wParam, lParam );
}

itWindow::itWindow( int width, int height ) : m_handle(0)
{
	m_ClientWidth = width;
	m_ClientHeight = height;
}

itWindow::~itWindow(void)
{
}

bool itWindow::Init()
{
	WNDCLASS wc = { 0 };
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WinProc;
	wc.hCursor = LoadCursor( NULL, IDC_ARROW );
	wc.lpszClassName = "WINWNDCLASS";

	if( !RegisterClass( &wc ) )
	{
		return false;
	}
	m_handle = CreateWindow( "WINWNDCLASS", "Faces", 
		WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
		100, 100, m_ClientWidth, m_ClientHeight,
		NULL, NULL, NULL, NULL );
	if( !m_handle ) return false;

	return true;
}

HWND itWindow::GetHandle()
{
	return m_handle;
}
