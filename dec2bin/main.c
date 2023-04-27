#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void revstr(char* str);
char* decimalToBinaryString(int num, const size_t sz)
{
	//Simple decimal to binary converter
	//num - input integer to convert, 
	//SZ - size of an output, padded with zeros to match the size
#ifdef _WIN32 
#ifdef _MSC_VER
//#include <sal.h>
	_Post_ _Notnull_ char* bin = (char*)malloc(sz) + 1;
	memset(_In_ bin, 48, sz); //WarningC6387: bin could be '0'
	bin[sz] = '\0';
#endif
#endif
#ifndef _WIN32
	char* bin = (char*)malloc(sz + 1);
	memset(bin, 48, sz);
	bin[sz] = 0;
#endif

	for (size_t i = 0; i < sz - 1; i++)
	{
		if (num % 2)
			bin[i] = '1'; //WarningC6386: buff overrun

		if (num)
			num /= 2;
	} bin[sz - 1] = '\0'; //WarningC6011: deref nullptr

	revstr(bin);
	return bin;
}

void revstr(char* str)
{
	char tmp;
	const size_t len = strlen(str);
	for (size_t i = 0; i < len / 2; i++) {
		tmp = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = tmp;
	}
}

int main()
{
	char* binstr = decimalToBinaryString(1337, 16);
	printf("%s\n", binstr);
	free(binstr);
	return 0;
}
