#include "stdafx.h"
#include "RegistKey.h"
#include "Check.h"
#include "etc.h"
//#pragma comment(lib, ".\\ExtraLib\\MySQL\\mysqlcppconn-static.lib")
//#include <mysqlx/xdevapi.h>
//#include <mysql/jdbc.h>

extern CString Key_md5;

//using namespace ::mysqlx;

BOOL CheckTheKey()
{
	if (!PreCheck())
	{
		RegistKey Dlg;
		int nSelect = Dlg.DoModal();
#ifdef DEBUG
		CString Result = MD5_Transcode(Dlg.Key_read);
#endif // DEBUG

		if (nSelect == IDOK && 
#ifdef DEBUG
			Result
#endif // DEBUG
#ifndef DEBUG
			MD5_Transcode(Dlg.Key_read)
#endif // !DEBUG			
			== Key_md5)
		{
			return TRUE;
		}
	}
	/*
	try
	{
		const char* url = "mysqlx://gurth@gurth.xyz";
	}
	catch (const mysqlx::Error& err)
	{
		CString CSerr;
		CSerr.Empty();
		CSerr.Format(L"%s", err);
		MessageBox(NULL, L"Error", L"Error: " + CSerr, MB_OK);
		return FALSE;
	}
	*/
#ifdef DEBUG
	return TRUE;
#endif // DEBUG

	return FALSE;
}

BOOL PreCheck()
{
	return FALSE;
}
