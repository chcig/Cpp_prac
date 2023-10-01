#include "Standard.h"

void ESTD::Estrcpy(char* dest, int dest_size, const char* source)
{
	for (int i = 0; i <= dest_size; i++)
		dest[i] = source[i];
}

int ESTD::Estrlen(const char* str)
{
	int nlen = 0;
	while (str[nlen] != '\0')
		nlen++;
	return nlen;
}

void ESTD::Estrcat(char* dest, const char* source)
{
	int i = 0,j = 0;
	while (dest[++i] != '\0');
	while (source[j] != '\0')
	{
		dest[i] = source[j++];
		++i;
	}
	dest[i] = '\0';
}

bool ESTD::Estrcmp(const char* dest, const char* source)
{
	for (int i = 0; i < Estrlen(dest); i++)
		if (dest[i] != source[i])
			return false;
	return true;
}

//char* ESTD::Estrtok(char*)