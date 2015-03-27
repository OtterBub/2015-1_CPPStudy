#include "Utill.h"

WORD win32_kbdown()
{
	INPUT_RECORD rec;
	DWORD dwReadDummy;
	DWORD dwWaitTime = 1;
	HANDLE hCin = GetStdHandle( STD_INPUT_HANDLE );
	//WAIT_OBJECT_0 == 0 ��, �ܼ��Է��� ������
	if( !WaitForSingleObject( hCin, dwWaitTime ) )
	{
		//�ܼ��Է� Ű���� �о üũ�Ѵ�
		ReadConsoleInput( hCin, &rec, 1, &dwReadDummy );
		if( rec.EventType == KEY_EVENT && rec.Event.KeyEvent.bKeyDown )
			return rec.Event.KeyEvent.wVirtualKeyCode;
	}
	return 0;
}

WORD win32_kbup()
{
	INPUT_RECORD rec;
	DWORD dwReadDummy;
	DWORD dwWaitTime = 1;
	HANDLE hCin = GetStdHandle( STD_INPUT_HANDLE );
	//WAIT_OBJECT_0 == 0 ��, �ܼ��Է��� ������
	if( !WaitForSingleObject( hCin, dwWaitTime ) )
	{
		//�ܼ��Է� Ű���� �о üũ�Ѵ�
		ReadConsoleInput( hCin, &rec, 1, &dwReadDummy );
		if( rec.EventType == KEY_EVENT && !(rec.Event.KeyEvent.bKeyDown) )
			return rec.Event.KeyEvent.wVirtualKeyCode;
	}
	return 0;
}