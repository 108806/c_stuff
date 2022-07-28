#include <windows.h>
#include <stdio.h>

int *nullptr = NULL;
int main()
{
	DWORD val;
	DWORD dataSize = sizeof(val);
	if (ERROR_SUCCESS == RegGetValueA(HKEY_LOCAL_MACHINE,
		"SYSTEM\\CurrentControlSet\\Control\\FileSystem", "LongPathsEnabled",
		RRF_RT_DWORD, nullptr /*type not required*/, &val, &dataSize))
	{
		printf("Value is %i\n", val);
		// no CloseKey needed because it is a predefined registry key
	}
	else { printf("Error reading.\n"); }
}
