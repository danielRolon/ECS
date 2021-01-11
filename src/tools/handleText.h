/* deprecated */

#pragma once

#include <string.h>

struct CharArray2
{
	CharArray2(){}
	CharArray2(CharArray2& charArray2)
	{
		this->data = charArray2.data;
		this->length = charArray2.length;
	}
	char** data = nullptr;
	unsigned int length = 0;
};

CharArray2 split(const char* string, char div);