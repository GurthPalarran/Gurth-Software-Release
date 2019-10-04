#include "stdafx.h"
#include "etc.h"
#include "ExtraLib/libMD5/md5.h"

CString MD5_Transcode(CString Src)
{
	md5_byte_t* data = (md5_byte_t*)Src.GetBuffer(Src.GetLength());
	md5_byte_t digest[16];
	md5_state_t md5StateT;
	md5_init(&md5StateT);
	md5_append(&md5StateT, data, Src.GetLength());
	md5_finish(&md5StateT, digest);
	char md5String[33] = { '\0' }, hexBuffer[3];
	for (size_t i = 0; i != 16; ++i)
	{
		if (digest[i] < 16)
			sprintf_s(hexBuffer, 3, "0%X", digest[i]);
		else
			sprintf_s(hexBuffer, 3, "%X", digest[i]);
		strcat_s(md5String, 33, hexBuffer);
	}
	CString ShowResult;
	ShowResult.Empty();
	ShowResult.Format(L"%s", md5String);

	return ShowResult;
}
