// ProcessTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Load DLL and handle reporting when it fails. 
#include <windows.h>
#include <WinBase.h>
#include <Strsafe.h>
#include <string.h>
#include <assert.h>     /* assert */

#include <stdio.h>  /* defines FILENAME_MAX */

#include <direct.h>
#define GetCurrentDir _getcwd

#include "Public/FCore.h"

void LoadFlathead();
void UnloadFlathead();

HINSTANCE FHDLL;

using namespace Flathead;

void fnlog(int type, const char *str)
{
	printf("LOG: %s\n", str);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		return errno;
	}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

	printf("The current working directory is %s", cCurrentPath);

	FCore* core = new FCore();
	core->SetLoggingFunction(fnlog);
	core->Initialize();

	delete core;

	return 0;
}