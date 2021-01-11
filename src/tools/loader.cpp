#include <tools/loader.h>

#include <sstream>
#include <string>
#include <string.h>

const char* loadFile(const char* path)
{
	std::ifstream stream(path);
	std::string line;
	std::stringstream ss;

	while(getline(stream, line))
	{
		ss << line << "\n";
	}

	std::string content = ss.str();
	const char* text = content.c_str();

	char* textCopy = new char[strlen(text)];
	strcpy(textCopy, text);

	return textCopy;
}