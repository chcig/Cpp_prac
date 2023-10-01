#pragma once

#ifndef _ESTD
#define _ESTD

namespace ESTD
{
	void Estrcpy(char* dest, int dest_size, const char* source);
	int Estrlen(const char* str);
	void Estrcat(char* dest, const char* source);
	bool Estrcmp(const char* dest, const char* source);
	//char* Estrtok(const )
}
#endif
